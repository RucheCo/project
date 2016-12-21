clc
clear all
close all

%% GENERAL
m = 60;
h = 60 * m;
j = 24 * h;
tMax = 1*j; 
tOn = 2; %sec
tOff = 60; %sec

rOn = tOn/(tOn+tOff);
rOff = tOff/(tOn+tOff);

t = 1:tMax;

Sunrise = 9*60*60;                          % Heure de lever du soleil
Sunset = 17*60*60;                          % Heure de coucher du soleil
T_soleil = Sunset - Sunrise;                % Heures de soleil par jour
Midday = (Sunrise+(Sunset-Sunrise)/2);      % Heure du zenith

E_batt_t = zeros(length(t),1);  
%% Récupération des spec

spec = readtable('specModules.xlsx','ReadRowNames',true,'ReadVariableNames',true);
pMoy = spec.tension .* (spec.consoOn * rOn + spec.consoOff * rOff);
spec = [spec array2table(pMoy)];

%% Batterie

% Modélisation de la batterie en se basant sur la datasheet. Condition 
% initiale : batterie chargée

Q_batt = 1050e-3;                                               % A.h
U_batt = 3.7;                                                   % V
E_batt = 3.9;                                                   % W.h
E_batt_t(1) = E_batt; 

%% Cellule solaire

% Modélisation du panneau solaire en se basant sur la datasheet. 
% L'irradiance a été calculée à partir des données du site :
% http://re.jrc.ec.europa.eu/pvgis/apps4/pvest.php pour la ville de Paris
% le mois de Décembre. P_sol_max représente la puissance que peut fournir
% le panneau dans les meilleures conditions (1000 W/m^2), P_sol_max_h
% représente la puissance que pourra fournir le panneau dans les conditions
% les plus défavorables

I_sol = 540e-3;                                                 % Ampères
U_sol = 5.5;                                                    % Volt
P_sol_max = U_sol * I_sol;                                      % Watt

Irradiance_max = 1000;                                          % W/m^2
Irradiance_h = 40;                                              % W/m^2

P_sol_max_h = P_sol_max * Irradiance_h / Irradiance_max;        % Watt

%% Courbe solaire

% Modélisation de la courbe du soleil. Résolution de 3 equations à
% 3 inconnues grace à polyfit

x = [Sunrise Midday Sunset];
y = [0 1 0];
p = polyfit(x,y,2);
a = p(1);
b = p(2);
c = p(3);

courbe_sol = a * mod(t,j).^2 + b * mod(t,j) + c;
ix = find(courbe_sol<0);
courbe_sol(ix) = 0;

P_tot_decharge = sum(spec.pMoy);
P_tot_charge = P_sol_max_h;

for cpt = t
    E_batt_t(cpt) = E_batt_t(cpt) + ...
                    P_tot_charge * courbe_sol(cpt) / 3600 - ... 
                    P_tot_decharge / 3600;
end
% pB ici

XMIN = 0;
XMAX = tMax;
YMIN = -0.1;
YMAX = 1.1;
plot(t, courbe_sol, t, E_batt_t)
ylabel('Courbe du soleil')
axis([XMIN XMAX YMIN YMAX])



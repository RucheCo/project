clc
clear all
close all

%% GENERAL
m = 60;
h = 60 * m;
j = 24 * h;
tMax = 10*j; 

t = 1:tMax;

Sunrise = 9*60*60;                          % Heure de lever du soleil
Sunset = 17*60*60;                          % Heure de coucher du soleil
T_soleil = Sunset - Sunrise;                % Heures de soleil par jour
Midday = (Sunrise+(Sunset-Sunrise)/2);      % Heure du zenith

E_batt_t = zeros(length(t),1);  
%% R�cup�ration des spec

spec = readtable('specModules.xlsx','ReadRowNames',true,'ReadVariableNames',true);
pMoy = spec.tension .* (spec.consoOn .* spec.rOn + spec.consoOff .* spec.rOff);
spec = [spec array2table(pMoy)];

%% Batterie

% Mod�lisation de la batterie en se basant sur la datasheet. Condition 
% initiale : batterie charg�e

Q_batt = 1050e-3;                                               % A.h
U_batt = 3.7;                                                   % V
E_batt_max = 3.9*h;                                          % W.s
E_batt_t(1) = E_batt_max; 

%% Cellule solaire

% Mod�lisation du panneau solaire en se basant sur la datasheet. 
% L'irradiance a �t� calcul�e � partir des donn�es du site :
% http://re.jrc.ec.europa.eu/pvgis/apps4/pvest.php pour la ville de Paris
% le mois de D�cembre. P_sol_max repr�sente la puissance que peut fournir
% le panneau dans les meilleures conditions (1000 W/m^2), P_sol_max_h
% repr�sente la puissance que pourra fournir le panneau dans les conditions
% les plus d�favorables

I_sol = 540e-3;                                                 % Amp�res
U_sol = 5.5;                                                    % Volt
P_sol_max = U_sol * I_sol;                                      % Watt

Irradiance_max = 1000;                                          % W/m^2
Irradiance_h = 40;                                              % W/m^2

P_sol_max_h = P_sol_max * Irradiance_h / Irradiance_max;        % Watt

%% Courbe solaire

% Mod�lisation de la courbe du soleil. R�solution de 3 equations �
% 3 inconnues grace � polyfit

x = [Sunrise Midday Sunset];
y = [0 1 0];
% p = polyfit(x,y,2);
% a = p(1);
% b = p(2);
% c = p(3);

a = -4.82253086419754e-09;
b = 0.000451388888888890;
c = -9.56250000000004;
courbe_sol = a * mod(t,j).^2 + b * mod(t,j) + c;
ix = find(courbe_sol<0);
courbe_sol(ix) = 0;

P_tot_decharge = sum(spec.pMoy);
P_tot_charge = P_sol_max_h;

for cpt = 2:length(t)
    E_batt_t(cpt) = E_batt_t(cpt-1) + ...
                    P_tot_charge * courbe_sol(cpt-1) - ... 
                    P_tot_decharge;
    if E_batt_t(cpt) > E_batt_max
        E_batt_t(cpt) = E_batt_max;
    elseif E_batt_t(cpt) < 0
        E_batt_t(cpt) = 0;
    end
end

figure
subplot(2,1,1);
XMIN = 0;
XMAX = tMax;
YMIN = -0.1;
YMAX = 1.1;
plot(t, courbe_sol/max(courbe_sol))
ylabel('Courbe du soleil')
axis([XMIN XMAX YMIN YMAX])
subplot(2,1,2);
XMIN = 0;
XMAX = tMax;
YMIN = -0.1;
YMAX = 1.1;
plot(t, E_batt_t/max(E_batt_t))
ylabel('Energie dans la batterie')
axis([XMIN XMAX YMIN YMAX])


clc
close all
clear all

t = 1:1:24*60; 

T_msg_j = 8;        % periode entre 2 messages en mode jour
T_msg_n = 60;       % periode entre 2 messages en mode nuit
H_mode_n = 21*60;   % mode nuit a partir de 19h
H_mode_j = 5*60;    % mode nuit a partir de 7h
nb_msg_sent_t = zeros(1,length(t));
nb_msg_sent = 0;

for cpt = t
    if (cpt < H_mode_j) || (cpt > H_mode_n)  % mode nuit
        if mod(cpt,T_msg_n) == 0
            nb_msg_sent = nb_msg_sent + 1;
        end
    end
    
    if (cpt > H_mode_j) && (cpt < H_mode_n) % mode jour
        if mod(cpt,T_msg_j) == 0
            nb_msg_sent = nb_msg_sent + 1;
        end
    end
    
    nb_msg_sent_t(cpt) = nb_msg_sent;
end

XMIN = 0;
XMAX = 24;
YMIN = 0;
YMAX = 140;
plot(t/60,nb_msg_sent_t);
xlabel('temps (heures)')
ylabel('nombre de msg envoyés')
axis([XMIN XMAX YMIN YMAX])


clc
clear all
close all

%% GENERAL
tMax = 24*60*60; 
tOn = 2; %sec
tOff = 60; %sec

rOn = tOn/(tOn+tOff);
rOff = tOff/(tOn+tOff);

t = 0:1:tMax;

spec = readtable('specModules.xlsx','ReadRowNames',true,'ReadVariableNames',true);
pMoy = spec.tension .* (spec.consoOn * rOn + spec.consoOff * rOff);
spec = [spec array2table(pMoy)];







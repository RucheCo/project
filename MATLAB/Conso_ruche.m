clc
clear all
close all

test = readtable('specModules.xlsx','ReadRowNames',true,'ReadVariableNames',true);

%% GENERAL
tMax = 24*60*60; 
tOn = 2; %sec
tOff = 60; %sec

rOn = tOn/(tOn+tOff);
rOff = tOff/(tOn+tOff);

t = 0:1:tMax;

%% ARDUINO
consoArduinoOn = 17e-3; %A
consoArduinoOff = 17e-6; %A

tensionArduino = 5; %V

pMoyArduino = tensionArduino * ( consoArduinoOn * rOn + consoArduinoOff * rOff ); %W

%% SIGFOX
consoSigfoxOn = 17e-3; %A
consoSigfoxOff = 17e-6; %A

tensionSigfox = 5; %V

pMoySigfox = tensionSigfox * ( consoSigfoxOn * rOn + consoSigfoxOff * rOff ); %W
%% RTC
consoRtcOn = 17e-3; %A
consoRtcOff = 17e-6; %A

tensionRtc = 5; %V

pMoyRtc = tensionRtc * ( consoRtcOn * rOn + consoRtcOff * rOff ); %W
%% GPS
consoGpsOn = 17e-3; %A
consoGpsOff = 17e-6; %A

tensionGps = 5; %V

pMoyGps = tensionGps * ( consoGpsOn * rOn + consoGpsOff * rOff ); %W
%% DS18B20
consoDs18b20On = 17e-3; %A
consoDs18b20Off = 17e-6; %A

tensionDs18b20 = 5; %V

pMoyDs18b20 = tensionDs18b20 * ( consoDs18b20On * rOn + consoDs18b20Off * rOff ); %W
%% DHT11
consoDht11On = 17e-3; %A
consoDht11Off = 17e-6; %A

tensionDht11 = 5; %V

pMoyDht11 = tensionDht11 * ( consoDht11On * rOn + consoDht11Off * rOff ); %W
%% LCD
consoLcdOn = 17e-3; %A
consoLcdOff = 17e-6; %A

tensionLcd = 5; %V

pMoyLcd = tensionLcd * ( consoLcdOn * rOn + consoLcdOff * rOff ); %W
%% HX711
consoHx711On = 17e-3; %A
consoHx711Off = 17e-6; %A

tensionHx711 = 5; %V

pMoyHx711 = tensionHx711 * ( consoHx711On * rOn + consoHx711Off * rOff ); %W







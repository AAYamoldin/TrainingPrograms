%% все траектории 
names = {'ECEF_BEIDOU.mat', 'ECEF_GALILEO.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};
colors = {'red','green','blue', 'cyan'};
leg = 'trace of ';
for j = 1 : length(names)
    load(names{j});
    figure;
for i = 1: size(x_ecef,2)
    if (i<10)
        plot3(reshape(x_ecef(:,i),1,[]), reshape(y_ecef(:,i),1,[]), reshape(z_ecef(:,i),1,[])/1000, 'color',[i/size(x_ecef,2) 0 1]);
    end
    if (i >= 10 && i<20)
        plot3(reshape(x_ecef(:,i),1,[]), reshape(y_ecef(:,i),1,[]), reshape(z_ecef(:,i),1,[])/1000, 'color',[1 i/size(x_ecef,2) 0]);
    end
    if (i >= 20)
        plot3(reshape(x_ecef(:,i),1,[]), reshape(y_ecef(:,i),1,[]), reshape(z_ecef(:,i),1,[])/1000, 'color',[0 1 i/size(x_ecef,2)]);
    end
    hold on;
    grid on;
    title(strcat('Моделирование траекторий спутников ', 32,systems{j}));
    xlabel('x, km');
    ylabel('y, km');
    zlabel('z, km');
    legendinfo{i} = ['trace of GLN ' num2str(i)];
    legend(legendinfo);
end
end


%% Дальность
ellipsoid = referenceEllipsoid('WGS84');
ff_cors = [55.7908, 49.1193,94.29];
[x,y,z] = geodetic2ecef(deg2rad(ff_cors(1)), deg2rad(ff_cors(2)),ff_cors(3), ellipsoid);

names = {'ECEF_BEIDOU.mat', 'ECEF_GALILEO.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};

for k = 1 : length(names)
load(names{k});
figure;
result = zeros(size(x_ecef,1), size(x_ecef,2));

for i = 1 :  size(x_ecef,1)
    for j = 1 : size(x_ecef,2)
        result(i,j) = norm([x_ecef(i,j)-x y_ecef(i,j)-y z_ecef(i,j)-z]);
    end
end

for i = 1: size(x_ecef,2)
    if (i<10)
        plot([1:size(x_ecef,1)]*0.5,result(:,i)/1000, 'color',[i/size(x_ecef,2) 0 1]);
    end
    if (i >= 10 && i<20)
        plot([1:size(x_ecef,1)]*0.5,result(:,i)/1000, 'color',[1 i/size(x_ecef,2) 0]);
    end
    if (i >= 20)
        plot([1:size(x_ecef,1)]*0.5, result(:,i)/1000, 'color',[0 1 i/size(x_ecef,2)]);
    end
    hold on;
    legendinfo{i} = ['distance of GLN ' num2str(i)];
    legend(legendinfo);
    xlabel('time, min');
    ylabel('distance, km');
    title(strcat('Изменение дальности месотположения каждого спутника',32,systems{k}));
end

end

%% Траектории выбранных спутников. GPS - 31, GLONASS - 26, GALILEO - 26, BEIDOU - 53

names = {'ECEF_BEIDOU.mat', 'ECEF_GALILEO.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
names = {'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};
colors = {'red','green','blue', 'cyan'};
leg = 'trace of ';
for j = 1 : length(names)
    load(names{j});
for i = 1: size(x_ecef,2)
    if i == 18
        plot3(reshape(x_ecef(:,i),1,[]), reshape(y_ecef(:,i),1,[]), reshape(z_ecef(:,i),1,[])/1000, 'color',[0 1 i/size(x_ecef,2)]);
        hold on;
        grid on;
        title(strcat('Моделирование траекторий спутников GPS'));
        xlabel('x, km');
        ylabel('y, km');
        zlabel('z, km');
        legendi = strcat('Trace of satelite', num2str(i));
        legend(legendi);
    end
end
end

%% Видимость ellipsoid = referenceEllipsoid('WGS84');
ff_cors = [55.7908, 49.1193,94.29];
names = {'ECEF_BEIDOU.mat', 'ECEF_GAL.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};
for i = 1 : length(names)
    figure;
    load(names{i});
    [az, elev, slant] = ecef2aer(x_ecef, y_ecef, z_ecef, ff_cors(1),ff_cors(2),ff_cors(3), ellipsoid);
    plot([1:size(x_ecef,1)]*0.5,deg2rad(elev))
    title(strcat('Изменение угла возвышения для систем ',32,  systems{i}));
    ylabel('degree');
    xlabel('time, min');
end
%% Графики фазовых измерений GPS
L1C_GPS_18 = KZN2_RAW_GNSS_DATA.GPS.G18.L1C;
L1X_GPS_18 = KZN2_RAW_GNSS_DATA.GPS.G18.L1X;
L2W_GPS_18 = KZN2_RAW_GNSS_DATA.GPS.G18.L2W;
L2X_GPS_18 = KZN2_RAW_GNSS_DATA.GPS.G18.L2X;
L5X_GPS_18 = KZN2_RAW_GNSS_DATA.GPS.G18.L5X;
phases = [L1C_GPS_18', L1X_GPS_18',L2W_GPS_18',L2X_GPS_18', L5X_GPS_18' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: 952,phases(:,i), 'LineWidth', 0.6);
end
legend('L1C','L1X','L2W','L2X','L5X');
title('Графики фазовых измерений для 18 спутника GPS');
xlabel('Время, с');
ylabel('Фаза, рад');
%% Графики фазовых измерений GALILEO
C1C = KZN2_RAW_GNSS_DATA.Galileo.E12.L7X;
C1P = KZN2_RAW_GNSS_DATA.Galileo.E12.L1X;
C2C = KZN2_RAW_GNSS_DATA.Galileo.E12.L8X;
C2C = KZN2_RAW_GNSS_DATA.Galileo.E12.L6X;
C3X = KZN2_RAW_GNSS_DATA.Galileo.E12.L5X;
phases = [C1C', C1P',C2C',C2C', C3X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1C),phases(:,i), 'LineWidth', 0.6);
end
legend('L7X','L1X','L8X','L6X','L5X');
title('Графики фазовых измерений для 12 спутника GALILEO');
xlabel('Время, с');
ylabel('Фаза, рад');

%% Графики фазовых измерений BEIDOU-7
C1C = KZN2_RAW_GNSS_DATA.Beidou.C07.L1X;
C1P = KZN2_RAW_GNSS_DATA.Beidou.C07.L6I;
C2C = KZN2_RAW_GNSS_DATA.Beidou.C07.L7I;
C2P = KZN2_RAW_GNSS_DATA.Beidou.C07.L2I;
C3X = KZN2_RAW_GNSS_DATA.Beidou.C07.L5X;
phases = [C1C', C1P',C2C',C2P', C3X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1C),phases(:,i), 'LineWidth', 0.6);
end
legend('L7X','L1X','L8X','L6X','L5X');
title('Графики фазовых измерений для 7 спутника BEIDOU');
xlabel('Время, с');
ylabel('Фаза, рад');

%% Графики фазовых измерений GLONASS-3
C1C = KZN2_RAW_GNSS_DATA.GLONASS.R03.L1C;
C1P = KZN2_RAW_GNSS_DATA.GLONASS.R03.L1P;
C2C = KZN2_RAW_GNSS_DATA.GLONASS.R03.L2C;
L2P_GLON_3 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L2P;
C3X = KZN2_RAW_GNSS_DATA.GLONASS.R03.L3X;
phases = [C1C', C1P',C2C',L2P_GLON_3', C3X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1C),phases(:,i), 'LineWidth', 0.6);
end
legend('L1C','L1P','L2C','L2P','L3X');
title('Графики фазовых измерений для 3 спутника GLONASS');
xlabel('Время, с');
ylabel('Фаза, рад');

%% График псевдодальностных измерений для beidou - 7
C1C = KZN2_RAW_GNSS_DATA.Beidou.C07.C1X;
C1P = KZN2_RAW_GNSS_DATA.Beidou.C07.C5X;
C2C = KZN2_RAW_GNSS_DATA.Beidou.C07.C2I;
C2P = KZN2_RAW_GNSS_DATA.Beidou.C07.C7I;
C3X = KZN2_RAW_GNSS_DATA.Beidou.C07.C6I;
phases = [C1C', C1P',C2C',C2P', C3X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1C),phases(:,i)/1000, 'LineWidth', 0.6);
end
legend('C1X','C5X','C2I','C7I','C6I');
title('Графики фазовых измерений для 7 спутника BEIDOU');
xlabel('Время, с');
ylabel('Расстояние, км');
%% График псевдодальностных измерений для GPS-18
C1C = KZN2_RAW_GNSS_DATA.GPS.G05.C1C;
C1P = KZN2_RAW_GNSS_DATA.GPS.G05.C1X;
C2C = KZN2_RAW_GNSS_DATA.GPS.G05.C2W;
C2P = KZN2_RAW_GNSS_DATA.GPS.G05.C2X;
C3X = KZN2_RAW_GNSS_DATA.GPS.G05.C5X;
phases = [C1C', C1P',C2C',C2P', C3X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1C),phases(:,i)/1000, 'LineWidth', 0.6);
end
legend('C1C','C1X','C2W','C2X','C5X');
title('Графики фазовых измерений для 18 спутника GPS');
xlabel('Время, с');
ylabel('Расстояние, км');

%% График псевдодальностных измерений для Glonass - 3
C1C = KZN2_RAW_GNSS_DATA.GLONASS.R03.C1C;
C1P = KZN2_RAW_GNSS_DATA.GLONASS.R03.C1P;
C2C = KZN2_RAW_GNSS_DATA.GLONASS.R03.C2C;
C2P = KZN2_RAW_GNSS_DATA.GLONASS.R03.C2P;
C3X= KZN2_RAW_GNSS_DATA.GLONASS.R03.C3X;
phases = [C1C', C1P',C2C',C2P', C3X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1C),phases(:,i)/1000, 'LineWidth', 0.6);
end
legend('C1C','C1P','C2C','C2P','C3X');
title('Графики фазовых измерений для 3 спутника Glonass');
xlabel('Время, с');
ylabel('Расстояние, км');
%% График псевдодальностных измерений для GALILEO-12
C1X = KZN2_RAW_GNSS_DATA.Galileo.E12.C1X;
C5X = KZN2_RAW_GNSS_DATA.Galileo.E12.C5X;
C7X = KZN2_RAW_GNSS_DATA.Galileo.E12.C7X;
C8X = KZN2_RAW_GNSS_DATA.Galileo.E12.C8X;
C6X = KZN2_RAW_GNSS_DATA.Galileo.E12.C6X;
phases = [C1X', C5X',C7X',C8X', C6X' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(C1X),phases(:,i)/1000, 'LineWidth', 0.6);
end
legend('C1X','C5X','C7X','C8X','C6X');
title('Графики фазовых измерений для 12 спутника Galileo');
xlabel('Время, с');
ylabel('Расстояние, км');

%% Графики изменения мощности сигнала 
A = KZN2_RAW_GNSS_DATA.Beidou.C07.S1X;
B = KZN2_RAW_GNSS_DATA.Beidou.C07.S5X;
C = KZN2_RAW_GNSS_DATA.Beidou.C07.S6I;

power = [A', B',C' ];
figure;
hold all;
for i = 1 :  size(power,2)
plot(power(:,i),'.');
end
legend('S1X','S5X','S6I');
title('Графики изменения мощности сигнала для 7 спутника Beidou');
xlabel('Время, с');
ylabel('Мощность, Вт');

A = KZN2_RAW_GNSS_DATA.GPS.G18.S1C;
B = KZN2_RAW_GNSS_DATA.GPS.G18.S1X;
C = KZN2_RAW_GNSS_DATA.GPS.G18.S2W;
D = KZN2_RAW_GNSS_DATA.GPS.G18.S2X;
E = KZN2_RAW_GNSS_DATA.GPS.G18.S5X;
power = [A', B',C',D', E' ];
figure;
hold all;
for i = 1 :  size(power,2)
plot(power(:,i),'.');
end
legend('S1C','S1X','S2W','S2X','S5X');
title('Графики изменения мощности сигнала для 18 спутника GPS');
xlabel('Время, с');
ylabel('Мощность, Вт');
%% Графики изменения мощности сигнала 
A = KZN2_RAW_GNSS_DATA.GLONASS.R03.S1C;
B = KZN2_RAW_GNSS_DATA.GLONASS.R03.S1P;
C = KZN2_RAW_GNSS_DATA.GLONASS.R03.S2C;
D = KZN2_RAW_GNSS_DATA.GLONASS.R03.S2P;
E = KZN2_RAW_GNSS_DATA.GLONASS.R03.S3X;
power = [A', B',C',D', E' ];
figure;
hold all;
for i = 1 :  size(power,2)
plot(power(:,i),'.');
end
legend('S1C','S1P','S2C','S2P','S3X');
title('Графики изменения мощности сигнала для 3 спутника Glonass');
xlabel('Время, с');
ylabel('Мощность, Вт');
%% Графики изменения мощности сигнала 
A = KZN2_RAW_GNSS_DATA.Galileo.E12.S1X;
B = KZN2_RAW_GNSS_DATA.Galileo.E12.S5X;
C = KZN2_RAW_GNSS_DATA.Galileo.E12.S7X;
D = KZN2_RAW_GNSS_DATA.Galileo.E12.S8X;
E = KZN2_RAW_GNSS_DATA.Galileo.E12.S6X;
power = [A', B',C',D', E' ];
figure;
hold all;
for i = 1 :  size(power,2)
plot(power(:,i),'.');
end
legend('S1X','S5X','S7X','S8X','S6X');
title('Графики изменения мощности сигнала для 12 спутника Galileo');
xlabel('Время, с');
ylabel('Мощность, Вт');



%% ПЭС по фазе для GPS-18, Glonass - 3, Galileo - 12, Beidou - 7

k = 40.308 * 10.^16;
c = 3 * 10.^8;
figure;
hold on;

% gps 
f1 = 1575.42*10.^6;
f2 = 1227.60*10.^6;
f5 = 1176.45;

lambda1 = c / f1;
lambda2 = c / f2;

L1 = KZN2_RAW_GNSS_DATA.GPS.G18.L1X;
L2 = KZN2_RAW_GNSS_DATA.GPS.G18.L2X; 

tec_l1_l2 = 1 / k * f1.^2*f2.^2 / (f1.^2 - f2.^2) * (L1 * lambda1 - L2 * lambda2);

scatter(1: length(tec_l1_l2),tec_l1_l2, 'LineWidth', 0.6);

% glonass -3

f1 = 1602 + 3*9/16*10.^6;
f2 = 1246 + 3*7/16*10.^6;

lambda1 = c / f1;
lambda2 = c / f2;

L1 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L1C;
L2 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L2C;
tec_l1_l2 = 1 / k * f1.^2*f2.^2 / (f1.^2 - f2.^2) * (L1 * lambda1 - L2 * lambda2);

scatter(1: length(tec_l1_l2),tec_l1_l2, 'LineWidth', 0.6);

% galileo - 12
f1 = 1575.42*10.^6;
f2 = 1176.45;

lambda1 = c / f1;
lambda2 = c / f2;

L1 = KZN2_RAW_GNSS_DATA.Galileo.E12.L1X;
L2 = KZN2_RAW_GNSS_DATA.Galileo.E12.L5X;
tec_l1_l2 = 1 / k * f1.^2*f2.^2 / (f1.^2 - f2.^2) * (L1 * lambda1 - L2 * lambda2);

scatter(1: length(tec_l1_l2),tec_l1_l2, 'LineWidth', 0.6);


%beiou - 7
f1 = 1575.42*10.^6;
f2 = 1191.79*10.^6;

lambda1 = c / f1;
lambda2 = c / f2;

L1 = KZN2_RAW_GNSS_DATA.Beidou.C07.L1X;
L2 = KZN2_RAW_GNSS_DATA.Beidou.C07.L5X;
tec_l1_l2 = 1 / k * f1.^2*f2.^2 / (f1.^2 - f2.^2) * (L1 * lambda1 - L2 * lambda2);

scatter(1: length(tec_l1_l2),tec_l1_l2, 'LineWidth', 0.6);

%% Построение графиков данных суптников
figure;
plot([1:length(KZN2_RAW_GNSS_DATA.GPS.G01.C1C)]/60, KZN2_RAW_GNSS_DATA.GPS.G01.C1C/1000);
title('Псевдодаьлность на частоте L1 канала кода C/A');
xlabel('Время, мин');
ylabel('Расстояние, км');
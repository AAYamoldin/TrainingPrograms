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
L1C_GLON_3 = KZN2_RAW_GNSS_DATA.Galileo.E12.L7X;
L1P_GLON_3 = KZN2_RAW_GNSS_DATA.Galileo.E12.L1X;
L2C_GLON_3 = KZN2_RAW_GNSS_DATA.Galileo.E12.L8X;
L2C_GLON_3 = KZN2_RAW_GNSS_DATA.Galileo.E12.L6X;
L3X_GLON_3 = KZN2_RAW_GNSS_DATA.Galileo.E12.L5X;
phases = [L1C_GLON_3', L1P_GLON_3',L2C_GLON_3',L2C_GLON_3', L3X_GLON_3' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(L1C_GLON_3),phases(:,i), 'LineWidth', 0.6);
end
legend('L7X','L1X','L8X','L6X','L5X');
title('Графики фазовых измерений для 12 спутника GALILEO');
xlabel('Время, с');
ylabel('Фаза, рад');

%% Графики фазовых измерений BEIDOU-7
L1C_GLON_3 = KZN2_RAW_GNSS_DATA.Beidou.C07.L1X;
L1P_GLON_3 = KZN2_RAW_GNSS_DATA.Beidou.C07.L6I;
L2C_GLON_3 = KZN2_RAW_GNSS_DATA.Beidou.C07.L7I;
L2I_B_7 = KZN2_RAW_GNSS_DATA.Beidou.C07.L2I;
L3X_GLON_3 = KZN2_RAW_GNSS_DATA.Beidou.C07.L5X;
phases = [L1C_GLON_3', L1P_GLON_3',L2C_GLON_3',L2I_B_7', L3X_GLON_3' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(L1C_GLON_3),phases(:,i), 'LineWidth', 0.6);
end
legend('L7X','L1X','L8X','L6X','L5X');
title('Графики фазовых измерений для 8 спутника BEIDOU');
xlabel('Время, с');
ylabel('Фаза, рад');

%% Графики фазовых измерений GLONASS-3
L1C_GLON_3 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L1C;
L1P_GLON_3 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L1P;
L2C_GLON_3 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L2C;
L2P_GLON_3 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L2P;
L3X_GLON_3 = KZN2_RAW_GNSS_DATA.GLONASS.R03.L3X;
phases = [L1C_GLON_3', L1P_GLON_3',L2C_GLON_3',L2P_GLON_3', L3X_GLON_3' ];
figure;
hold all;
for i = 1 :  size(phases,2)
scatter(1: length(L1C_GLON_3),phases(:,i), 'LineWidth', 0.6);
end
legend('L1C','L1P','L2C','L2P','L3X');
title('Графики фазовых измерений для 3 спутника GLONASS');
xlabel('Время, с');
ylabel('Фаза, рад');
%% Построение графиков данных суптников
figure;
plot([1:length(KZN2_RAW_GNSS_DATA.GPS.G01.C1C)]/60, KZN2_RAW_GNSS_DATA.GPS.G01.C1C/1000);
title('Псевдодаьлность на частоте L1 канала кода C/A');
xlabel('Время, мин');
ylabel('Расстояние, км');
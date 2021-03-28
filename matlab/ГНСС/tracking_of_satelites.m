%% create 27 plots

leg = 'trace of ';
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
    title('Моделирование траекторий спутников BEIDOU');
    xlabel('x, km');
    ylabel('y, km');
    zlabel('z, km');
    legendinfo{i} = ['trace of GLN ' num2str(i)];
    legend(legendinfo);
end
%% все траектории на один график
names = {'ECEF_BEIDOU.mat', 'ECEF_GAL.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};
colors = {'red','green','blue', 'cyan'};
figure;
hold all;
for i = 1 : length(names)
    load(names{i});
    for j = 1 : size(x_ecef,2)
        plot3(reshape(x_ecef(:,j),1,[])/1000, reshape(y_ecef(:,j),1,[])/1000, reshape(z_ecef(:,j),1,[])/1000, 'color', colors{i});
    end
    hold all;
    legendinfo{i} = ['trace of ' systems{i}];
    grid on;
        title('Моделирование траекторий спутников');
        xlabel('x, km');
        ylabel('y, km');
        zlabel('z, km');
        view(3);
     legend(legendinfo);
end



%% Перевод координат 
ellipsoid = referenceEllipsoid('WGS84'); 
[phi, lambda, h] = ecef2geodetic(x_ecef, y_ecef, z_ecef, ellipsoid);
plot(rad2deg(lambda), rad2deg(phi));
title('2D график геодезических координат GALILEO');
xlabel('Долгота, градусы');
ylabel('Широта, градусы');
for i = 1: size(x_ecef,2)
legendinfo{i} = ['Координаты ' num2str(i)];
end
legend(legendinfo);

%% Полярные системы координат
ellipsoid = referenceEllipsoid('WGS84');
ff_cors = [55.7908, 49.1193,94.29];
names = {'ECEF_BEIDOU.mat', 'ECEF_GAL.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};
for i = 1 : length(names)
    figure;
    load(names{i});
    [az, elev, slant] = ecef2aer(x_ecef, y_ecef, z_ecef, ff_cors(1),ff_cors(2),ff_cors(3), ellipsoid);
    polar(deg2rad(az), elev)
    title(strcat('Проекции траекторий движения спутников ',32,  systems{i}));
    xlabel('degree');
end


%% Дальность
ellipsoid = referenceEllipsoid('WGS84');
ff_cors = [55.7908, 49.1193,94.29];
[x,y,z] = geodetic2ecef(deg2rad(ff_cors(1)), deg2rad(ff_cors(2)),ff_cors(3), ellipsoid);

names = {'ECEF_BEIDOU.mat', 'ECEF_GAL.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
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

%% Зависимость азимут (az)
ellipsoid = referenceEllipsoid('WGS84');
ff_cors = [55.7908, 49.1193,94.29];
names = {'ECEF_BEIDOU.mat', 'ECEF_GAL.mat', 'ECEF_GLONASS.mat', 'ECEF_GPS.mat'};
systems = {'Beidou', 'Galileo', 'Glonass', 'GPS'};
for i = 1 : length(names)
    figure;
    load(names{i});
    [az, elev, slant] = ecef2aer(x_ecef, y_ecef, z_ecef, ff_cors(1),ff_cors(2),ff_cors(3), ellipsoid);
    plot([1:size(x_ecef,1)]*0.5,az)
    title(strcat('Изменение азимута для систем ',32,  systems{i}));
    ylabel('degree');
    xlabel('time, min');
end

%%  и угла возвышения(elem)

ellipsoid = referenceEllipsoid('WGS84');
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


        
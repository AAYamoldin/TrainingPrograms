function task1
% Определяем синал и шаблон
clc; clear all; clf;
t = 0 : 0.1 : 25;
x = sin(t/2) + sin(3*t);
t_template = 7 : 0.1 : 9;
x_template = sin(t_template/2 ) + sin(3 * t_template);
figure;
hold all;
plot(t,x,'g', t_template, x_template, 'b--o');
title('Оригинальный ряд и шаблон');
legend('Ряд', 'Шаблон');
% Реализуем скользящую свертку
start_position = 1;
dot_results = [];
while (start_position + length(t_template) <= length(t))
    dot_results(start_position) = dot(x_template, x(start_position: (start_position + length(x_template) - 1)));
    start_position = start_position + 1;
end

[a,b] = max(dot_results);%максимум соответсвует концу шаблона
start_point = (b - length(t_template)) * 0.1;%начало шаблона в сигнале
xline(start_point);
end
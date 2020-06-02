%у нас есть входной сигнал длиной М точек его нужно предсказывать по N
%точкам на основе линейного предсказания
clc, clear, clear all;
% создаю входной сигнал длиной М(=1001) точек
x = [0 : 0.1 : 100];
M = length(x);
signal = sin(x);
% cоздаю количество точек по которым предсказать
N = 900;
% линейное предсказание = перемножение матрицы весов w и матрицы признаков X
% pred = X * w
% для этого нам нужно реализовать алгоритм машинного обучения 
% на обучающей выборке signal
% матрица признаков , размерности (M-N) x (N-1) 
X = [];
i = 1;
j = 1;
start_index = 1;
while start_index <= M - N% заполнение матрицы Х
    while j <= N
        X(start_index , j) = signal(i);
        j = j + 1;
        i = i + 1;
    end
    j = 1;
    start_index = start_index + 1;
    i = start_index;
end

pred = [];
i = N + 1;
while i <= M%заполнение матрицы полученных значений
    pred(i - N , 1) = signal(i);
    i = i + 1;
end

w = X\pred;%это решение. и чо с ним делать?

% проверка решения

reshenie = X * w;
figure;
hold all;
plot(x,signal);
plot(x(N:end-1),reshenie);
legend('Это сигнал который был', 'это сигнал, предсказанный по N точкам');


%% это не нужно, но пока жаль удалять

function res = stochastic_gradient_step(X, y, w, train_ind)
eta = 0.01;
size_of_matrix = size(X,1);
random_string = X(train_ind, :);
grad0 = 2/size_of_matrix * ((random_string * w))
end

function stds = mserror(y, y_pred)
stds = sum((y_pred - y).^2/length(y_pred))
end


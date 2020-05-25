
function lklklk
clc; clear all; clf;
a = [0.0000595 0.0000595 0.0000595 0.0002381 0.0003572 0.0002381 0.0000595];
b = [1.0000 -3.7087 5.2313 -3.3234 0.8020];
t = 0 : 0.1 : 25;
x = sin(t/2) + sin(3*t);
y = filter(a, b, x);
z=myFilter(b,a,x);
hold all;
plot(t,x,'g');
plot(t,y,'.b');
plot(t,z,'or');
legend('Orig','filter','MyFilt')
end
 
function y = myFilter(a, b, x)
na=length(a);
nb=length(b);
y = zeros(1,length(x));
for n=max(na,nb):length(x);
    y(n)=b(1)*x(n);
    NB=0; NA=0;
    for k=2:nb
        NB=NB+b(k)*x(n-k+1);
    end
    for k=2:na
        NA=NA+a(k)*y(n-k+1);
    end    
    y(n)=y(n)+NB-NA;
     y(n)=y(n)*a(1);
end
end
 
%   a(1)*y(n) = b(1)*x(n) + b(2)*x(n-1) + ... + b(nb+1)*x(n-nb)
%                         - a(2)*y(n-1) - ... - a(na+1)*y(n-na)
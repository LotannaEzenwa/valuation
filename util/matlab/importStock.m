function [ output_args ] = importStock(ticker)
%IMPORTSTOCK Grabs a stock's data from storage
%   Assumes a static filestructure. Here, it's in ../../data
cf = pwd;
clean = 'make clean';
make = 'make';

exe='./stock';
dn = '/../quandl/';
data = '/../../data/';
ext = '.csv';

s = strcat(cf,data,ticker,ext);


if exist(s,'file') == 2
    cd(strcat(pwd,data))
    sheet = readtable(strcat(ticker,ext));
else
    cd(strcat(cf,dn));
    if exist([pwd '/' exe],'file') ~= 2
        system(make)
    end
    system([exe,' ',ticker])
    cd(strcat(pwd,data));
    sheet = readtable(strcat(ticker,ext));
    
    
end

cd(cf)

output_args = flipud(sheet);
end


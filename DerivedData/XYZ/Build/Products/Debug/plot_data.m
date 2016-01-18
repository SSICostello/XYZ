circle(0,0,6378.140e3)
hold
Data = importdata('osc.txt');
plot(Data(:,2),Data(:,3))
axis('square')
grid
hold off


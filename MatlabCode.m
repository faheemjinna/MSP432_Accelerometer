clear s
s = serialport("/dev/cu.usbmodemM43210051",9600)

for i = 1:1000
    data = readline(s)

    %Splitting the data and seperating it to x, y and z.
    splitdata = strsplit(data,"\t") 

    x = splitdata(1)
    y = splitdata(2)
    z = splitdata(3)
    
    %Coverting the String value to double
    x_double = str2double(x)
    y_double = str2double(y)
    z_double = str2double(z)

    %Plotting the 3d Graph.
    plot3(x_double,y_double,z_double,"bo",'MarkerSize',5)

    grid on 
    xlim([0,1000])
    ylim([0,1000])
    zlim([0,1000])

    xlabel("X axis")
    ylabel("Y axis")
    zlabel("Z axis")
    end
clear s;
#include <stdio.h>
#include <stdlib.h>

void input_readings(int sensors, int readings, int arr[sensors][readings]){
    for(int i = 0; i < sensors; i++){
        for(int j = 0; j < readings; j++){
            printf("Sensor %d, hour %d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void sensor_analysis(int sensors, int readings, int arr[sensors][readings],int sensor_num){
    int sum=0,max=-99999,min=99999,critical=0,warning=0,current=0,longest=0;
    float avg=0.0;
    for(int i=0;i<readings;i++){
        if(arr[sensor_num][i]>max) max=arr[sensor_num][i];
        if(arr[sensor_num][i]<min) min=arr[sensor_num][i];
        if(arr[sensor_num][i]>=40) critical++;
        if(arr[sensor_num][i]>=35 && arr[sensor_num][i]<=39) warning++;
        if(arr[sensor_num][i]>=35){
            current++;
            if(current>longest) longest = current;
        }
        else{
            current = 0;
        }
        sum=sum+arr[sensor_num][i];
    }
    avg = (float)sum/readings;
    printf("Sensor %d:\n",sensor_num+1);
    printf("Total = %d    ",sum);
    printf("Average = %.2f    ",avg);
    printf("Max = %d    ",max);
    printf("Min = %d\n",min);
    printf("Critical = %d    ",critical);
    printf("Warning = %d    ",warning);
    printf("Longest hot streak = %d\n",longest);

}





int main(){
    int sensors, readings;
    printf("Enter number of sensors: ");
    scanf("%d", &sensors);
    printf("Enter number of hourly readings: ");
    scanf("%d", &readings);

    int (*arr)[readings] = malloc(sensors * sizeof(int[readings]));

    input_readings(sensors, readings, arr);
    for(int i=0;i<sensors;i++){
        sensor_analysis(sensors,readings,arr,i);
    }
    free(arr);
    return 0;
}
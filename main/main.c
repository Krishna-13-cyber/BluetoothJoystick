#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/adc.h>

void adc_task(void *arg)
{
  //  adc1_config_width(ADC_WIDTH_BIT_12);
   // adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_DB_11); 
    //int val = adc1_get_raw(ADC1_CHANNEL_0);
	adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_3,ADC_ATTEN_DB_11); 
    int val1 = adc1_get_raw(ADC1_CHANNEL_3);
    adc1_config_width(ADC_WIDTH_BIT_12);
adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_11); 
    int val2 = adc1_get_raw(ADC1_CHANNEL_6);
    while(1)
	{	
     //  val = adc1_get_raw(ADC1_CHANNEL_0);
       val1 = adc1_get_raw(ADC1_CHANNEL_3);
       val2 = adc1_get_raw(ADC1_CHANNEL_6);
     //printf("Value : %d ",  val);
      if(val1>=0&&val1<=1000)
       {
	printf("Forwards");//printf("Value1 : %d ",  val1);
	printf("Value : %d ",val1);
	}
       
      else if(val1>=4000&&val1<=4095)
       {
	printf("Backwards");  //printf("Value2 : %d ",  val2);
	printf("Value : %d ",val1);
	} 
	else
       {
	printf("No movement"); 
	printf("Value : %d ",val1); 
	}
	      printf("\n");
     // printf("%d\n","%d\n",val1,val2);
        vTaskDelay(10 / portTICK_PERIOD_MS);  
    }
}
void app_main(void)
{
    xTaskCreate(&adc_task,"adc_task",4096,NULL,1,NULL);
}

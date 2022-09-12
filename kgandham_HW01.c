#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>

#define MAXCHAR 1000
char data[MAXCHAR][MAXCHAR];
int main(){
    FILE *fp;
    char row[MAXCHAR];
    char tempdata[MAXCHAR],tempdata1[MAXCHAR];
    char *token;
    char degree[MAXCHAR][MAXCHAR];
    char departments[MAXCHAR][MAXCHAR];
    // char Advisor[MAXCHAR][MAXCHAR];
    int degreecount = 0,pos = 0,startpos = 0,found = 0,value=0,datacount=0;
    float temp,highestgpa = 0;
    int i,findex=0;
        int studentcount = 0;
    char *temptoken;
    int temppos = 0;
    float cradit = 0;
    fp = fopen("students_dataset.csv","r");
    int xpos = 0;

    char tempdata2[MAXCHAR],tempdata12[MAXCHAR];
    char *token2;
    char *temptoken2;
char tempdata3[MAXCHAR],tempdata13[MAXCHAR];
    char *token3;
    char *temptoken3;
    
    // while (feof(fp) != true)
    while(fgets(row, MAXCHAR, fp)!=NULL)
    {
        
        
        if(xpos !=0){
            strcpy(data[datacount],row);
            datacount++;
        }
        xpos++;
    }
   

    for (int j = 0; j < datacount; ++j)
    {
        
        strcpy(tempdata,data[j]);
        token = strtok(tempdata, ",");
        pos = 1;
        if(startpos >= 0){
            while(token != NULL)
            {
                
                token = strtok(NULL, ",");

                if(pos == 3){
                    
                    if(degreecount == 0){
                        strcpy(degree[degreecount],token);
                        degreecount++;
                    }else{
                        for (i = 0; i < degreecount; i++)
                        {
                            value=strcmp(degree[i],token); 

                            if(value == 0){
                                found = 1;
                            }
                        }
                        if(found == 0){

                          strcpy(degree[degreecount],token);
                          degreecount++;
                        }
                    }
                }
                
                pos++;
            }
        }
        startpos++;
        found = 0;
    }
    printf("----------------------------------------------------------\n");
    printf("Total number of degrees are : %d \n",degreecount);

    for (i = 0; i < degreecount; i++)
    {
        printf("Degree: %s\n", degree[i]);
    }
    printf("----------------------------------------------------------\n");
    int cpos = 0;
    float sech = 0,thirdh = 0;

    float gpaarray[3];
    int gpapos =0;
    for (int j = 0; j < datacount; ++j)
    {
        //printf("data: %s\n", data[j]);
        strcpy(tempdata,data[j]);
        token = strtok(tempdata, ",");
        pos = 1;
        while(token != NULL)
        {
            token = strtok(NULL, ",");
            if(pos == 4){
		 //printf("Token %s\n",token);	
                 temp  = atof(token);
                 gpaarray[gpapos] = temp;
                 gpapos++;
                if(highestgpa < temp){
	            thirdh = sech; 
		    sech = highestgpa;
                    highestgpa = temp;     	
                }

                else if(sech < temp && (highestgpa > temp)){
		    thirdh = sech;
                    sech = temp;
 		    
                }

                else if(thirdh < temp && (sech > temp)){
                    thirdh = temp;
                }
            }
            if(pos == 5){
                temp  = atof(token);
                cradit = cradit+temp; 
                cpos++;
            }
            pos++;
        }
        
    }
    gpaarray[0] = highestgpa;
    gpaarray[1] = sech;
    gpaarray[2] = thirdh;
  
    //printf("1:%f 2:%f 3:%f\n",gpaarray[0],gpaarray[1],gpaarray[2]);
    float a;

    /*for (i = 0; i < gpapos; ++i) 
    {
        for (int j = i + 1; j < gpapos; ++j) 
        {
            if (gpaarray[i] < gpaarray[j]) 
            {
                a = gpaarray[i];
                gpaarray[i] = gpaarray[j];
                gpaarray[j] = a;
            }
        }
    }*/
    printf("Top Students and their GPAs:\n");
    printf("First Highest gpa is  %f \n",gpaarray[0]);

    for (int j = 0; j < datacount; ++j)
    {
        
        strcpy(tempdata,data[j]);
        token =  strtok(tempdata, ",");
        strcpy(tempdata1,data[j]);
        
        
        pos = 1;	
	temppos = 0;
        while(token != NULL)
        {
            token = strtok(NULL, ",");
            if(pos == 4){
                temp  = atof(token);
                if((gpaarray[0] == temp) && (studentcount <3)){
                    temptoken = strtok(tempdata1, ",");
                    while(temptoken != NULL)
                    {   
                                              
                        if(temppos == 0){
                            printf("1st highest Student name: %s ", temptoken);
                        }
                        if(temppos == 1){
                            printf("%s\n", temptoken);
                        }
                        temptoken = strtok(NULL, ",");  
                        temppos++;

                        

                    }
                    
                    studentcount++;
                }
            }
            pos++;
        }
    }

    
    printf("Second highest GPA is %f \n",gpaarray[1]);
    studentcount = temppos = 0;
    for (int j = 0; j < datacount; ++j)
    {
        
        strcpy(tempdata2,data[j]);
        token2 =  strtok(tempdata2, ",");
        strcpy(tempdata12,data[j]);
        
        
        pos = 1;
	temppos = 0;
        while(token2 != NULL)
        {
            token2 = strtok(NULL, ",");
            if(pos == 4){
                temp  = atof(token2);
                if((gpaarray[1] == temp) && (studentcount < 3)){
                    temptoken2 = strtok(tempdata12, ",");
                    while(temptoken2 != NULL)
                    {   
                        if(temppos == 0){
                            printf("2nd student name: %s ", temptoken2);
                        }
                        if(temppos == 1){
                            printf("%s\n", temptoken2);
                        }
                        temptoken2 = strtok(NULL, ",");  
                        temppos++;

                        

                    }
                    
                    studentcount++;
                }
                
            }
            pos++;
        }
    }

    
    printf("Third Highest GPA is %f \n",gpaarray[2]);
    studentcount = temppos = 0;
    for (int j = 0; j < datacount; ++j)
    {
        
        strcpy(tempdata3,data[j]);
        token3 =  strtok(tempdata3, ",");
        strcpy(tempdata13,data[j]);
        
        
        pos = 1;
	temppos = 0;
        while(token3 != NULL)
        {
            token3 = strtok(NULL, ",");
            if(pos == 4){
                temp  = atof(token3);
                if((gpaarray[2] == temp) && (studentcount <3)){
                    temptoken3 = strtok(tempdata13, ",");
                    while(temptoken3 != NULL)
                    {   
                                              
                        if(temppos == 0){
                            printf("3rd student name: %s ", temptoken3);
                        }
                        if(temppos == 1){
                            printf("%s\n", temptoken3);
                        }
                        temptoken3 = strtok(NULL, ",");  
                        temppos++;

                        

                    }
                    
                    studentcount++;
                }
                
            }
            pos++;
        }
    }
        
    printf("----------------------------------------------------------\n");
    printf("average credit hours is  %f \n",(float)(cradit/(cpos)));
    printf("----------------------------------------------------------\n");

    char majortemp[MAXCHAR];
    float gpa = 0;
    int ccount=0;
    value = 0;
    for (int j = 0; j < datacount; ++j)
    {
        strcpy(tempdata,data[j]);
        token = strtok(tempdata, ",");
        pos = 1;
        float tempgpa = 0; 
        
        while(token != NULL)
        {
            token = strtok(NULL, ",");
            if(pos == 2){
                
                strcpy(majortemp,token);
            }
            if(pos == 4){
                 temp  = atof(token);
               tempgpa = temp; 
            }
            pos++;
        }
        value=strcmp(majortemp,"Computer Science");
        if(value == 0){
            ccount++;
            gpa += tempgpa;
        }

        
    }
    printf("----------------------------------------------------------\n");
    printf("average gpa is  %f for Computer Science\n",(gpa/(ccount)));
    printf("----------------------------------------------------------\n");


    degreecount = 0;
    int advisor[MAXCHAR];
    char advisorname[datacount][100];
    for (int j = 0; j < datacount; ++j)
    {
        
        strcpy(tempdata,data[j]);
        token = strtok(tempdata, ",");
        pos = 1;
        if(startpos != 0){
            while(token != NULL)
            {
                //printf("Token: %s\n", token);
                token = strtok(NULL, ",");

                if(pos == 2){
                    //printf("Token: %s\n", token);
                    if(degreecount == 0){
                        strcpy(departments[degreecount],token);
                        advisor[degreecount] = 1;
                        degreecount++;
                    }else{
                        for (i = 0; i < degreecount; i++)
                        {
                            value=strcmp(departments[i],token); 

                            if(value == 0){
                                found = 1;
                                advisor[i] = (advisor[i]+1);
                            }
                        }
                        if(found == 0){

                          strcpy(departments[degreecount],token);
                          advisor[degreecount] = 1;
                          degreecount++;
                        }
                    }
                }
                
                pos++;
            }
        }
        startpos++;
        found = 0;
    }


    startpos =0;
     for (i = 0; i < degreecount; i++)
    {
        int k =0;value=0;
        for (int j = 0; j < datacount; ++j)
        {
            
            strcpy(tempdata,data[j]);
            strcpy(tempdata1,data[j]);
            token = strtok(tempdata, ",");
            pos = 1,value = 0;
            if(startpos >= 0){
                while(token != NULL)
                {
                    token = strtok(NULL, ",");
                    if(pos == 2){
                        
                        value=strcmp(departments[i],token); 
                        
                    }
                    
                    pos++;
                }
                if(value == 0){
                    temppos = 0;
                    temptoken = strtok(tempdata1, ",");
                    while(temptoken != NULL)
                    {   
                        if(temppos == 7){
                           strcpy(advisorname[k],temptoken);
                            k++;
                        }
                        temptoken = strtok(NULL, ",");  
                        temppos++;
                    }
                    
                }
            }
        }
	
        int unique_count = 0,x,y;
        for ( x = 0; x < k; x++) {
            for ( y = x + 1; y < k; y++)
                if (strcmp(advisorname[x], advisorname[y]) == 0)
                    break;
                if (y == k)
                    unique_count++;
        }
        advisor[i] = unique_count;

        startpos++;
        found = 0;
    }

    for (i = 0; i < degreecount; i++)
    {
        printf("Major: %s : %d \n", departments[i],advisor[i]);
    }
    printf("----------------------------------------------------------\n");
    fclose(fp);
    return 0;
}
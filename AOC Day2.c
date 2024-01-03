#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct Farger
{
  char a[6];
    int b;
};
int main()
{
    struct Farger Farg[3] = {{"blue", 0}, {"red", 0}, {"green", 0}};
    int blue = 14, red = 12, green = 13;
    char Line[1000];
    char *pg;
    char *color;
    int check=0;
    char *token;
    int PointOfSemikolon;
    int gametoken=0;
    char temp[1000];
    int result=0;
    char *semikolon = ":";
    char *kommakolon = ";";
    char *komma = ",";
    FILE *fp = fopen("data.txt", "r");
    while (fgets(Line, sizeof(Line), fp) != NULL)
    {
        check = 0;
        Farg[0].b =0;
        Farg[1].b =0;
        Farg[2].b=0;
        gametoken+=1;
        printf("NEW GAME:GAME %d\n",gametoken);
        PointOfSemikolon = strcspn(Line, semikolon);
        strncpy(temp, Line + PointOfSemikolon + 1, strlen(Line) - PointOfSemikolon -1 );
        pg = strtok(temp,kommakolon);
        while(pg != NULL){
            color=strtok_r(pg,komma,&token);
            
    
        while (color != NULL)
        {  
        
            for (int i = 0; i < 3; i++)
            {
                if (strstr(color, Farg[i].a)!= NULL)
                {
                
                    
                    for (int j = 0; j < strlen(color); j++)
                    {
                        if (isdigit(color[j]))
                        { 

                            Farg[i].b = atoi(&color[j]); 
                            printf("The color:%s has %d points\n",Farg[i].a,Farg[i].b);
                            if(Farg[0].b>blue || Farg[1].b>red || Farg[2].b>green){
                                printf("IMPOSSIBLE GAME: GAME %d\n",gametoken);
                                check = -1;
} 
                        }
                        
                       
                    }
                }
            }
        
        

            color = strtok_r(NULL, komma,&token);
        }
         

        pg =strtok(NULL,kommakolon);
     
        
    }       
    if(check == 0){
      result += gametoken;
      printf("POSSIBLE GAME:%d\n", gametoken);
    }
    }

    printf("%d\n",result);    
    fclose(fp);
    return 0;
}

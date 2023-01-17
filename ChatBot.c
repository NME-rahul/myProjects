#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
int main()
{
    FILE *fn,*fp,*ft,*fj,*fd,*fq,*fr;
    char intr[30],intr2[30],intr3[30],intr4[30],intr5[30];
    char password[15],tag[15],name[15],info[50],joke;
    int i;
    system("COLOR A");
    printf("->Say Something to me\n\n");
    printf("- save my password \t - open whatsapp \t - tell me a joke \t - todays weather\n\n");
    //printf("->Hi!,i am your friend");

    while(1)
    {
        start :
        printf("\n->");
        gets(intr);
        if(strcmp(intr,"hi")==0 || strcmp(intr,"hello")==0 || strcmp(intr,"hey")==0 || strcmp(intr,"hlw")==0 || strcmp(intr,"hy")==0 || strcmp(intr,"hey buddy")==0 || strcmp(intr,"namastey")==0)
        {
            printf("->Hi!,there");
            gets(intr2);
            if()
            {
                fscanf(fr,"%s",name);
               printf(""); 
            }
        }
        else if(strcmp(intr,"exit")==0)
        {
            printf("->See you soon!");
            exit(0);
        }
        else if(strcmp(intr,"born")==0 )
        {
            printf("->On time 03:06:2021 by Rahul");
        }
        else if(strcmp(intr,"time")==0 || strcmp(intr,"what is time")==0  || strcmp(intr,"day")==0  || strcmp(intr,"month")==0  || strcmp(intr,"year")==0  || strcmp(intr,"date")==0 )
        {
                time_t t;
            time(&t);
            printf("->Time : %s", ctime(&t));
        }
        else if(strcmp(intr,"open chrome")==0 || strcmp(intr,"open the chrome")==0 )
        {
            printf("->opening...");
            system("start chrome");
        }
         else if(strcmp(intr,"open instagram")==0 || strcmp(intr,"instagram")==0 )
        {
            printf("->opening...");
            system("start https://www.instagram.com/");
        }
         else if(strcmp(intr,"open facebook")==0 || strcmp(intr,"facebook")==0 )
        {
            printf("->opening...");
            system("start https://www.facebook.com/");
        }
        else if(strcmp(intr,"open whatsapp")==0 || strcmp(intr,"whatsapp")==0 )
        {
            printf("->opening...");
            system("start https://web.whatsapp.com/");
        }
         else if(strcmp(intr,"open youtube")==0)
         {
             printf("->opening...");
             system("start https://www.youtube.com/");
         }
         else if(strcmp(intr,"open maps")==0 || strcmp(intr,"google maps")==0)
         {
             printf("->opening...");
             system("start https://www.google.co.in/maps/@26.9072203,75.7952836,15z?hl=en-GB&authuser=0");
         }
          else if(strcmp(intr,"compose mail")==0 || strcmp(intr,"compose gmail")==0 || strcmp(intr,"gmail")==0 || strcmp(intr,"mail")==0 || strcmp(intr,"open mail")==0 || strcmp(intr,"open gmail")==0)
        {
            printf("->Ok");
            system("start https://mail.google.com/mail/u/0/#inbox?compose=new");
        }
          else if(strcmp(intr,"open cmd")==0 || strcmp(intr,"cmd")==0 )
        {
            printf("->opening...");
            system("start cmd");
        }
         else if(strcmp(intr,"tell me a joke")==0 || strcmp(intr,"joke")==0 || strcmp(intr,"tell me joke")==0 || strcmp(intr,"joke sunao")==0 || strcmp(intr,"ek joke sunao")==0)
        {
            joke:
            printf("-> Father: aaj Aanganbadi kyu nhi gye\n Beta: Kal vo log mujhe tol rhe the kya ta aaj bech de");
            printf("\n->");
            gets(intr2);
            if(strcmp(intr2,"next")==0 || strcmp(intr2,"ek aur")==0 || strcmp(intr2,"aur")==0 || strcmp(intr2,"or")==0 || strcmp(intr2,"ek or")==0)
            {
                printf("->Shadi ek esa din h jha\nJab ladka stage per apni dulhan k sath bethe hue\n Dusri ladkiyo ko dekh ye sochta h ki\n Phle kha mar gyi thi ye laadkiya\n->");
                  gets(intr3);
            if(strcmp(intr3,"next")==0 || strcmp(intr3,"ek aur")==0 || strcmp(intr3,"aur")==0 || strcmp(intr3,"or")==0 || strcmp(intr3,"ek or")==0)
            {
                printf("->Poti:Aapne apna jevan bima kyu nhi karwaya\n\t Dadaji: Taki mere marne k bad tum log sach me dukhi ho\n->");
                gets(intr4);
            if(strcmp(intr4,"next")==0 || strcmp(intr4,"ek aur")==0 || strcmp(intr4,"aur")==0 || strcmp(intr4,"or")==0 || strcmp(intr4,"ek or")==0)
            {
                printf("->Poti:Aapne apna jevan bima kyu nhi karwaya\n\t Dadaji: Taki mere marne k bad tum log sach me dukhi ho->");
                gets(intr5);
            if(strcmp(intr5,"next")==0 || strcmp(intr5,"ek aur")==0 || strcmp(intr5,"aur")==0 || strcmp(intr5,"or")==0 || strcmp(intr5,"ek or")==0)
            {
                printf("->Danda sir pe marlo sahab... Piche wali jeb me quarter rakha h\n\t Lockdown me desh ki bigidi hui economy ko sudharne me log hat btate hue ");
            }
            else
            {
                goto start;
            }
            }
            else
            {
                goto start;
            }
            }
            }
            else
            {
                goto start;
            }



            /*gets(intr2);
            if(strcmp(intr2,"next")==0 || strcmp(intr2,"ek aur")==0 || strcmp(intr2,"aur")==0 || strcmp(intr2,"or")==0 || strcmp(intr2,"ek or")==0)
            {
                do
                {
                    i=0;
                    j=fopen("Jokes.txt","r");
                    while(1)
                    {
                        fseek(fj,i,SEEK_CUR);
                        joke=fgetc(fj);
                        if(fj==EOF)
                        {
                            break;
                        }
                        fscanf(fj,"%c",joke);
                        printf("%c",joke);
                        i++;
                    }
                    gets(intr3);
                }
                while()
            }*/

        }
         else if(strcmp(intr,"who is my gf?")==0 || strcmp(intr,"who is my gf")==0 || strcmp(intr,"who is rahuls gf")==0 || strcmp(intr,"who is rahuls girfriend")==0 || strcmp(intr,"my ex")==0 || strcmp(intr,"your ex")==0)
        {
            printf("->You are single yet");
        }
         else if(strcmp(intr,"who built you")==0 || strcmp(intr,"whose your creater")==0 || strcmp(intr,"your birth date")==0 || strcmp(intr,"your creater")==0 || strcmp(intr,"when was you born")==0 || strcmp(intr,"where you built")==0 || strcmp(intr,"father")==0 || strcmp(intr,"you father")==0 || strcmp(intr,"mother")==0|| strcmp(intr,"your mother")==0)
        {
            printf("->Rahul built me! on date 06:07:2021 in jaipur, Rajasthan");
        }
         else if(strcmp(intr,"open notepad")==0 )
        {
            printf("->opening...");
            system("start notepad");
        }
         else if(strcmp(intr,"you are useless")==0 || strcmp(intr,"you do not know")==0 || strcmp(intr,"you don't know")==0)
        {
            printf("->sorry!,\ni am growing\nHelp me to grow");
        }
         else if(strcmp(intr,"are you my friend")==0 || strcmp(intr,"we are friends")==0 || strcmp(intr,"friends")==0 || strcmp(intr,"friends?")==0 || strcmp(intr,"wiil you be my friend")==0 || strcmp(intr,"wiil you be my friend?")==0)
        {
            printf("->yes! we are friends");
        }
         else if(strcmp(intr,"tell me todays weather")==0 || strcmp(intr,"today's weather")==0  || strcmp(intr,"weather")==0 || strcmp(intr,"todays weather")==0)
        {
            printf("->todays weather is");
            system("start https://www.google.com/search?q=todays+weather&oq=todays+&aqs=chrome.0.0i433i457i512j69i57j0i402j0i512j0i433i512j0i10i131i433i512j0i433i512j0i512j0i131i433i512j0i512.3631j1j7&sourceid=chrome&ie=UTF-8");
        }
          else if(strcmp(intr,"what is my name")==0 || strcmp(intr,"name")==0 || strcmp(intr,"mera name kya h")==0 )
        {
           fn=fopen("user name.txt","r");
           fscanf(fn,"%s",name);
           puts(name);
        }
          else if(strcmp(intr,"save this information")==0 || strcmp(intr,"save")==0  || strcmp(intr,"save this")==0 || strcmp(intr,"note it")==0 || strcmp(intr,"note down this")==0)
        {
            printf("->Ok\n");
            fp=fopen("saved information","a");
            while(1)
            {
                gets(info);
                fputs(info,fp);
            }
            fclose(fp);
            system("cls");
        }
        else if(strcmp(intr,"save my password")==0)
         {
             printf("->please save by a tag \n");
             ft=fopen("my password.txt","w");
             gets(password);
             fputs(password,ft);
             //fprintf(ft,"%s",password);
             fclose(ft);
             system("cls");
             printf("->done!");
         }
         /*else if(strcmp(intr,"my password")==0 || strcmp(intr,"what is my password")==0)
         {
             rewind(ft);
             printf("->please enter the tag of password(like gmail or phone)");
             gets(tag);
             ft=fopen("my password.txt","r+");
             while(1)
             {
                fread(&password,sizeof(password),1,ft);
                if(strcmp(password,tag)==0)
                {
                    printf("%s",password);
                    break;
                }
             }
         }*/
           else if(strcmp(intr,"what is your name?")==0 || strcmp(intr,"your name")==0 || strcmp(intr,"what is your name")==0 )
        {
            printf("->My Name is Ava");
        }
        else if(strcmp(intr,"can you speak in english?")==0 || strcmp(intr,"can you speak in english")==0 || strcmp(intr,"can you speak in English")==0 || strcmp(intr,"can you speak in English?")==0)
        {
            printf("-> No, i can only speak in English");
        }
           else if(strcmp(intr,"will you marry me?")==0 || strcmp(intr,"marry me")==0  || strcmp(intr,"will you marry me")==0 || strcmp(intr,"are you married")==0 || strcmp(intr,"are you married?")==0)
        {
            printf("->No, i am married/compiled with C");
            printf("\n->");
            gets(intr2);
            if(strcmp(intr2,"why")==0)
            {
                printf("->because i am already married");
            }

            else if(strcmp(intr2,"friends")==0 || strcmp(intr2,"will you be my friend")==0 || strcmp(intr2,"will you be my friend?")==0 || strcmp(intr2,"ok")==0 || strcmp(intr2,"friends?")==0 || strcmp(intr2,"friend?")==0 )
            {
                printf("->yes! we are friends forever");
            }
            else
            {
                goto start;
            }
        }
         else if(strcmp(intr2,"will you be my gf")==0 || strcmp(intr2,"will you be my girlfriend")==0 || strcmp(intr2,"will you be my girlfriend?")==0 || strcmp(intr2,"are you my gf")==0 || strcmp(intr2,"are you my girlfriend")==0 || strcmp(intr2,"will you be my boyfriend")==0 || strcmp(intr2,"will you be my boyfriend?")==0 || strcmp(intr2,"will you be my bf")==0)
            {
                printf("->No, you can search for other");
            }
        else if(strcmp(intr,"are you bot")==0 || strcmp(intr,"are you a bot")==0 || strcmp(intr,"are you a chat bot")==0 || strcmp(intr,"you are bot")==0 || strcmp(intr,"you are bot?")==0)
        {
            printf("->Yes, i am a chat bot");
        }
         else if(strcmp(intr,"sad")==0 || strcmp(intr,"i am feeling sad")==0 || strcmp(intr,"i am not felling well")==0 || strcmp(intr,"i am sad")==0)
        {
            printf("->How can i help you \n\t wants listen songs\n->");
            gets(intr2);
            if(strcmp(intr2,"no need")==0 || strcmp(intr2,"no")==0)
            {
                printf("->OK");
            }
            else if(strcmp(intr2,"play music")==0 || strcmp(intr2,"songs")==0  || strcmp(intr2,"song")==0 || strcmp(intr2,"play song")==0)
            {
                printf("->Ok");
            system("start https://music.youtube.com/watch?v=UqyT8IEBkvY&list=RDAMVMUqyT8IEBkvY");
            }
            else if(strcmp(intr2,"need medical help")==0 || strcmp(intr2,"medical")==0  || strcmp(intr2,"help me")==0)
            {
                printf("->Go to nearest hospital");
                system("start https://www.google.com/search?q=hospital+near+me&rlz=1C1ONGR_enIN966IN966&oq=hospital+&aqs=chrome.1.69i57j0i433i457i512j0i402l2j46i433i512j0i433i512j0i512j0i433i512l3.3886j1j7&sourceid=chrome&ie=UTF-8");
                gets(intr3);
                if(strcmp(intr2,"useles")==0 || strcmp(intr2,"you are useles")==0 || strcmp(intr2,"you are dumb")==0 | strcmp(intr2,"dumb machine")==0)
                {
                printf("-> you can write your feedback \n\t i will try resolve your problem");
                gets(intr4);
                fq=fopen("Feedback.txt","a");
                fprintf(fq,"%s",intr4);
                }
                else
                    goto start;
            }
            else if(strcmp(intr2,"some personal")==0 || strcmp(intr2,"personal")==0  || strcmp(intr2,"need personal help")==0)
            {
                printf("->You can tell me anything, i will not say it to anybody");
                printf("\n->");
                gets(intr3);
                if(strcmp(intr3,"no")==0 || strcmp(intr3,"you are not trusted")==0 || strcmp(intr3,"you are trustful?")==0 || strcmp(intr3,"not trust on you")==0)
                {
                    printf("->i am trusted your information will not be leak");
                    printf("\n->");
                    gets(intr5);
                    if(strcmp(intr5,"no")==0);
                    {
                        printf("->Ok");
                        goto start;
                    }
                }
                else
                {
                    fp=fopen("saved information","a");
                    while(1)
               {
                    printf("->Ok\n->");
                    gets(intr4);
                    //scanf("%s",&info[50][50]);
                    fprintf(fn,"%s",info);
                    system("cls");
                }
                }
            }
        }
        else if(strcmp(intr2,"need medical help")==0 || strcmp(intr2,"medical")==0  || strcmp(intr2,"help me")==0  || strcmp(intr2,"help")==0)
            {
                printf("-> Go to nearest hospital");
                system("start https://www.google.com/search?q=hospital+near+me&rlz=1C1ONGR_enIN966IN966&oq=hospital+&aqs=chrome.1.69i57j0i433i457i512j0i402l2j46i433i512j0i433i512j0i512j0i433i512l3.3886j1j7&sourceid=chrome&ie=UTF-8");
                gets(intr3);
                if(strcmp(intr2,"useles")==0 || strcmp(intr2,"you are useles")==0 || strcmp(intr2,"you are dumb")==0 | strcmp(intr2,"dumb machine")==0)
                {
                printf("-> you can write your feedback \n\t i will try resolve your problem");
                gets(intr4);
                fq=fopen("Feedback.txt","a");
                fprintf(fq,"%s",intr4);
                }
                else
                    goto start;
            }
        else if(strcmp(intr,"songs")==0  || strcmp(intr,"song")==0 || strcmp(intr,"play music")==0 || strcmp(intr,"play song")==0 || strcmp(intr,"can you suggest me a good song?")==0 || strcmp(intr,"can you suggest me a good song")==0)
        {
            music:
            printf("->Ok");
            system("start https://music.youtube.com/watch?v=UqyT8IEBkvY&list=RDAMVMUqyT8IEBkvY");
            gets(intr2);
            if(strcmp(intr2,"change song")==0|| strcmp(intr2,"next")==0 || strcmp(intr2,"change the song")==0 || strcmp(intr2,"play hindi song")==0 || strcmp(intr2,"play hindi songs")==0 || strcmp(intr2,"hindi song")==0)
            {
                system("start https://www.youtube.com/watch?v=DkhZ3H5IelU&list=RDJFYCc577kjQ&index=5");
            }
             else if(strcmp(intr2,"play hindi song")==0 || strcmp(intr2,"play hindi songs")==0 || strcmp(intr2,"hindi song")==0 || strcmp(intr2,"play sad hindi song")==0 )
            {
                system("start https://www.youtube.com/watch?v=tLqtnGLfm4Q");
            }
            else
            {
                system("start https://www.youtube.com/watch?v=T94PHkuydcw");
            }
        }
        else if(strcmp(intr,"restart pc")==0 )
        {
            printf("->Ok...");
            system("shutdown -l -f");
        }
        else if(strcmp(intr,"what is your favorite song")==0 || strcmp(intr,"what is your favorite song?")==0 || strcmp(intr,"what is your favorite food?")==0 || strcmp(intr,"what is your favorite food")==0 || strcmp(intr,"what is your favorite colour?")==0  || strcmp(intr,"what is your favorite colour")==0 || strcmp(intr,"what is your favorite actor")==0 || strcmp(intr,"what is your favorite actor?")==0 || strcmp(intr,"what is your favorite actoress?")==0 || strcmp(intr,"what is your favorite actoress")==0 || strcmp(intr,"what is your favorite movie?")==0 || strcmp(intr,"what is your favorite movie")==0)
        {
            printf("->I'm a computer program bot and i only like energy");
        }
          else if(strcmp(intr,"you like me")==0 || strcmp(intr,"you like me?")==0 || strcmp(intr,"like me?")==0 || strcmp(intr,"like me")==0)
        {
            printf("->Yes!, I like you");
        }
        else if(strcmp(intr,"how you feeling today?")==0 || strcmp(intr,"how you feeling today")==0)
        {
            printf("-> Felling good today and you");
            gets(intr2);
            if(strcmp(intr2,"good")==0 || strcmp(intr2,"nice")==0 || strcmp(intr2,"feeling nice today")==0 || strcmp(intr2,"feeling good")==0 || strcmp(intr2,"feeling nice")==0)
            {
                printf("->Feeling nice to know!");
            }
            else if(strcmp(intr2,"bad")==0 || strcmp(intr2,"not good")==0 || strcmp(intr2,"not feeling nice today")==0 || strcmp(intr2,"not feeling good")==0 || strcmp(intr2,"feeling bad today")==0)
            {
                printf("->You an share your feelings with me");
                fd=fopen("personal.txt","a");
                gets(intr3);
                fputs(intr3,fd);
                if(strcmp(intr3,"songs")==0  || strcmp(intr3,"song")==0 || strcmp(intr3,"play music")==0 || strcmp(intr3,"play song")==0 || strcmp(intr3,"can you suggest me a good song?")==0 || strcmp(intr3,"can you suggest me a good song")==0)
                {
                    goto music;
                }
                else if(strcmp(intr,"tell me a joke")==0 || strcmp(intr,"joke")==0 || strcmp(intr,"tell me joke")==0 || strcmp(intr,"joke sunao")==0 || strcmp(intr,"ek joke sunao")==0)
                {
                    goto joke;
                }
                else
                {
                    goto start;
                }
            }
            else
            {
                goto start;
            }
        }
          else
        {
            printf("->unable to understand\n you can try Wikipedia search");
            system("start https://www.wikipedia.org/");
        }
    }
    return 0;
}


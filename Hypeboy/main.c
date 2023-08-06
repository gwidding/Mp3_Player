#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE* pFile;

#define ARRAYSIZE 100
#define SONGNAME_SIZE 25
#define SONGARTIST_SIZE 25
#define TRACK_NUMBER
#define FILE_PATH "mp3_list.txt"

void Show_mp3_library(void);
void mp3_play(void);
void add_song(void);
void delete_song(void);


typedef struct mp3rec
{
    char songname[SONGNAME_SIZE];
    char artist[SONGARTIST_SIZE];
    char track[30];
    int minutes;
    int seconds;
} MP3REC;

MP3REC song_list[ARRAYSIZE];
int songcount = 0;

char name_line[SONGNAME_SIZE + 2];
char artist_line[SONGARTIST_SIZE + 2];
int minutes;
int seconds;

int main(void)
{
    int menuchoice = 0;

    while (menuchoice != 5)
    {
        printf("**************--------------*****************\n");
        printf("**************| MP3 Player |****************\n");
        printf("**************--------------****************");

        printf("\n1:~ Show the MP3 Library");
        printf("\n2:~ Play an MP3 Song");
        printf("\n3:~ Add Song to the MP3 Library");
        printf("\n4:~ Delete Song in the MP3 Library");
        printf("\n5:~ Quit the Program");

        printf("\n\nEnter Choice From 1-5: ");
        scanf("%d", &menuchoice);

        switch (menuchoice)
        {
        case 1:
            Show_mp3_library();
            break;

        case 2:
            mp3_play();
            break;

        case 3:
            add_song();
            break;

        case 4:
            delete_song();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\n[!] Invalid Choice: 1-5 Only Please\n\n");
        }

    };
    system("pause");
}


void Show_mp3_library(void)
{
    printf("\n\n Show the MP3 Library\n\n");

    FILE * fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        printf("mp3_list를 열 수 없습니다.\n");
    }
    else {
        printf("---------[ Playlist ]---------\n");
        printf(" Track N. ARTIST - MUSIC \n");
        printf("------------------------------\n");
        char word[ARRAYSIZE];
        int line_count = 0;
        while (fgets(word, ARRAYSIZE, fp) != NULL) {
            line_count++;
            printf("Track %d. %s", line_count, word);
        }
        fclose(fp);
        printf("\n\n");       
    }
}

void mp3_play(void)
{
    printf("\n\n Play an MP3 Song\n\n");
    printf("ılı.lıllılı.ıllı.♪~\n");

    {
 //       int songnumber =0;
        char commandarray[ARRAYSIZE];
        char mp3filename[ARRAYSIZE] = "NewJeans - Hype Boy.mp3";

        sprintf(commandarray, "C:\\mplayer\\\"%s\"", mp3filename);
        printf("\nAttempting to Run Command: %s...\n\n", commandarray);
        system(commandarray);

        int menuchoice = 0;
        printf("\n1: Back To Menu");
        printf("\n2: Quit");

        printf("\n\nEnter Choice From 1-2: ");
        scanf("%d", &menuchoice);

        switch (menuchoice)
        {
        case 1:
            main();
            break;
        case 2:
            //system("wmplayer.exe /playstate:1");
            printf("\nDone.\n\n");
            system("pause");
            break;
        default:
            printf("\nInvalid Choice: 1-2 Only Please\n");
            mp3_play();
        }
    }
}

void add_song(void)
{
    printf("\n\n add song to the mp3 library\n\n");
    FILE* fp = fopen(FILE_PATH, "a");
    if (fp == NULL) printf("mp3_list를 열 수 없습니다.\n");
    else {
        char input_artist[ARRAYSIZE];
        char input_song[ARRAYSIZE];
        printf("추가할 가수 : ");
        //scanf("%s",song_list[0].artist);
        scanf("%s", input_artist);

        printf("곡 제목 : ");
        //scanf("%s", song_list[0].)
        scanf("%s", input_song);

        fprintf(fp, "\n%s - %s", input_artist, input_song);
        fclose(fp);
    }

}

void delete_song(void)
{
    printf("\n\n Delete File\n\n");

 //   int i;
    int track_number;

    int line_count = 1;
    FILE* fp = fopen(FILE_PATH, "r");
    FILE* tmpfile = fopen("temp.txt", "w");
    if (fp == NULL || tmpfile == NULL) 
        printf("파일을 열 수 없습니다.");

    printf("Please Enter the track number that you wish to delete:");
    scanf("%d", &track_number);

    char word[ARRAYSIZE];
    while (fgets(word, ARRAYSIZE, fp) != NULL) {

        if (line_count == track_number) line_count++;
        else {
            fprintf(tmpfile, "%s", word);
            line_count++;
        }
    }
    fclose(fp);
    fclose(tmpfile);

    int nResult = remove(FILE_PATH);
    if (nResult == 0) printf("원래 파일 삭제 완료\n");
    else printf("다시 확인하십시오.\n");

    rename("temp.txt", "mp3_list.txt");
    printf("%d번 트랙이 삭제되었습니다.\n", track_number);
}
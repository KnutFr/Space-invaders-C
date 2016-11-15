#include "stdafx.h"
#include "my.h"

int   playmusic(char *mySound)
{
  FMOD_RESULT   resultat;
  
  resultat = FMOD_System_CreateSound(sys, mySound, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  if (resultat != FMOD_OK)
    {
      fprintf(stderr, "Cannot read the sound mp3\n");
      exit(EXIT_FAILURE);
    }
  FMOD_Sound_SetLoopCount(musique, -1);
  FMOD_System_PlaySound(sys, FMOD_CHANNEL_FREE, musique, 0, NULL);
  return (1);
}

void  init_sound()
{
  FMOD_System_Create(&sys);
  FMOD_System_Init(sys, 1, FMOD_INIT_NORMAL, NULL);
}

int   playsound(char *mySound)
{
  FMOD_RESULT   resultat;

  resultat = FMOD_System_CreateSound(sys, mySound, FMOD_SOFTWARE | FMOD_2D |\
				     FMOD_CREATESTREAM, 0, &musique);
  if (resultat != FMOD_OK)
    {
      fprintf(stderr, "Cannot read the sound mp3\n");
      exit(EXIT_FAILURE);
    }
  FMOD_Sound_SetLoopCount(musique, 1);
  FMOD_System_PlaySound(sys, FMOD_CHANNEL_FREE, musique, 0, NULL);
  return (1);
}
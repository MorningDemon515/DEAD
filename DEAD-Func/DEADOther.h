
#include "..\DEAD\DEADmain.h"

class DEADOther
{
public:
   void LoopAudio(ALuint s);
   void SetAudioPitch(ALuint s,ALfloat p);
   void SetAudioVolume(ALuint s,ALfloat v);
   void SetAudioPan(ALuint s, ALfloat p);
   void SetAudio2d(ALuint s, ALfloat x,ALfloat y);
   void SetAudio3d(ALuint s, ALfloat x,ALfloat y,ALfloat z);

   void PauseAudio(ALuint s);
   void ResumeAudio(ALuint s);
};
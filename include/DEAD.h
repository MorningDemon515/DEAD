
#ifdef _MSC_VER
#define DEAD(x) __declspec(dllexport) x
#else
#define DEAD(x) extern "C" x
#endif

typedef void DEADvoid;
typedef unsigned int DEADuint; 
typedef float DEADfloat;

   DEAD(DEADuint) DEAD_Load_OGG(const char* file);
   DEAD(DEADuint) DEAD_Load_WAV(const char* file);
   DEAD(DEADuint) DEAD_Load_MP3(const char* file);
   DEAD(DEADuint) DEAD_Load_AIFF(const char* file);
   DEAD(DEADuint) DEAD_Load_FLAC(const char* file);
   DEAD(DEADuint) DEAD_Load_AAC(const char* file);
   DEAD(DEADuint) DEAD_Load_APE(const char* file);
   DEAD(DEADuint) DEAD_Load_MIDI(const char* file);
   DEAD(DEADuint) DEAD_Load_MPEG4(const char* file);

   DEAD(void) DEAD_Init();

   DEAD(DEADuint) DEAD_Set_Audio(DEADuint buffer);
   DEAD(void) DEAD_Set_Audio2D(DEADuint s, DEADfloat x,DEADfloat y);
   DEAD(void) DEAD_Set_Audio3D(DEADuint s, DEADfloat x,DEADfloat y,DEADfloat z);
   DEAD(void) DEAD_Loop_Audio(DEADuint s);
   DEAD(void) DEAD_Set_Pitch(DEADuint s,DEADfloat pitch);
   DEAD(void) DEAD_Set_Volume(DEADuint s,DEADfloat volume);
   DEAD(void) DEAD_Set_Pan(DEADuint s,DEADfloat pan);
   DEAD(void) DEAD_Pause_Audio(DEADuint s);
   DEAD(void) DEAD_Resume_Audio(DEADuint s);

   DEAD(void) DEAD_Play_Audio(DEADuint s);
   DEAD(void) DEAD_Play_AudioToEnd(DEADuint s);

   DEAD(int) DEAD_Get_Error();

   DEAD(void) DEAD_Free();
   DEAD(void) DEAD_Free_Buffer(DEADuint buffer);
   DEAD(void) DEAD_Free_Audio(DEADuint audio);	
	



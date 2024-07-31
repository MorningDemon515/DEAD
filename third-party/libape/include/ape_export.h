
#ifndef APE_EXPORT_H
#define APE_EXPORT_H

#ifdef APE_STATIC_DEFINE
#  define APE_EXPORT
#  define APE_NO_EXPORT
#else
#  ifndef APE_EXPORT
#    ifdef APE_EXPORTS
        /* We are building this library */
#      define APE_EXPORT 
#    else
        /* We are using this library */
#      define APE_EXPORT 
#    endif
#  endif

#  ifndef APE_NO_EXPORT
#    define APE_NO_EXPORT 
#  endif
#endif

#ifndef APE_DEPRECATED
#  define APE_DEPRECATED __declspec(deprecated)
#endif

#ifndef APE_DEPRECATED_EXPORT
#  define APE_DEPRECATED_EXPORT APE_EXPORT APE_DEPRECATED
#endif

#ifndef APE_DEPRECATED_NO_EXPORT
#  define APE_DEPRECATED_NO_EXPORT APE_NO_EXPORT APE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef APE_NO_DEPRECATED
#    define APE_NO_DEPRECATED
#  endif
#endif

#endif /* APE_EXPORT_H */

#pragma once

#include <QtCore/qglobal.h>

#ifndef QT_STATIC
# if defined(TRIANGLEPLUGIN_LIB)
#  define TRIANGLEPLUGIN_EXPORT Q_DECL_EXPORT
# else
#  define TRIANGLEPLUGIN_EXPORT Q_DECL_IMPORT
# endif
#else
# define TRIANGLEPLUGIN_EXPORT
#endif

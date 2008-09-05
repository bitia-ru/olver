#include <err.h>
#include "common/agent.h"
#include "ncurses/string/printf_agent.h"
#include "ncurses/string/scanf_agent.h"
#include "process/process/functionTypedValuesCall.h"
#include "util/format/printf_agent.h"
#include "util/format/scanf_agent.h"
#include "util/format/wprintf_agent.h"
#include "util/format/wscanf_agent.h"

#define Switch_1of1_0_ByValue( funcName )                                                                         \
switch ( arguments->elements[ 0 ].type ) {                                                                        \
    case IntTObjCode       : return func( format, arguments->elements[ 0 ].data.IntTObj        );                 \
    case CharTObjCode      : return func( format, arguments->elements[ 0 ].data.CharTObj       );                 \
    case ShortTObjCode     : return func( format, arguments->elements[ 0 ].data.ShortTObj      );                 \
    case LongTObjCode      : return func( format, arguments->elements[ 0 ].data.LongTObj       );                 \
    case LLongTObjCode     : return func( format, arguments->elements[ 0 ].data.LLongTObj      );                 \
    case IntMaxTObjCode    : return func( format, arguments->elements[ 0 ].data.IntMaxTObj     );                 \
    case SizeTObjCode      : return func( format, arguments->elements[ 0 ].data.SizeTObj       );                 \
    case PtrDiffTObjCode   : return func( format, arguments->elements[ 0 ].data.PtrDiffTObj    );                 \
    case WIntTObjCode      : return func( format, arguments->elements[ 0 ].data.WIntTObj       );                 \
    case FloatTObjCode     : return func( format, arguments->elements[ 0 ].data.FloatTObj      );                 \
    case DoubleTObjCode    : return func( format, arguments->elements[ 0 ].data.DoubleTObj     );                 \
    case LongDoubleTObjCode: return func( format, arguments->elements[ 0 ].data.LongDoubleTObj );                 \
    case CStringCode       : return func( format, arguments->elements[ 0 ].data.CString        );                 \
    case WStringCode       : return func( format, arguments->elements[ 0 ].data.WString        );                 \
    case VoidTPtrObjCode   : return func( format, arguments->elements[ 0 ].data.VoidTPtrObj    );                 \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type ); \
             return -1;                                                                                           \
}

#define Switch_1of1_1_ByValue( funcName, v1 )                                                                     \
switch ( arguments->elements[ 0 ].type ) {                                                                        \
    case IntTObjCode       : return func( v1, format, arguments->elements[ 0 ].data.IntTObj        );             \
    case CharTObjCode      : return func( v1, format, arguments->elements[ 0 ].data.CharTObj       );             \
    case ShortTObjCode     : return func( v1, format, arguments->elements[ 0 ].data.ShortTObj      );             \
    case LongTObjCode      : return func( v1, format, arguments->elements[ 0 ].data.LongTObj       );             \
    case LLongTObjCode     : return func( v1, format, arguments->elements[ 0 ].data.LLongTObj      );             \
    case IntMaxTObjCode    : return func( v1, format, arguments->elements[ 0 ].data.IntMaxTObj     );             \
    case SizeTObjCode      : return func( v1, format, arguments->elements[ 0 ].data.SizeTObj       );             \
    case PtrDiffTObjCode   : return func( v1, format, arguments->elements[ 0 ].data.PtrDiffTObj    );             \
    case WIntTObjCode      : return func( v1, format, arguments->elements[ 0 ].data.WIntTObj       );             \
    case FloatTObjCode     : return func( v1, format, arguments->elements[ 0 ].data.FloatTObj      );             \
    case DoubleTObjCode    : return func( v1, format, arguments->elements[ 0 ].data.DoubleTObj     );             \
    case LongDoubleTObjCode: return func( v1, format, arguments->elements[ 0 ].data.LongDoubleTObj );             \
    case CStringCode       : return func( v1, format, arguments->elements[ 0 ].data.CString        );             \
    case WStringCode       : return func( v1, format, arguments->elements[ 0 ].data.WString        );             \
    case VoidTPtrObjCode   : return func( v1, format, arguments->elements[ 0 ].data.VoidTPtrObj    );             \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type ); \
             return -1;                                                                                           \
}

#define Switch_1of1_2_ByValue( funcName, v1, v2 )                                                                 \
switch ( arguments->elements[ 0 ].type ) {                                                                        \
    case IntTObjCode       : return func( v1, v2, format, arguments->elements[ 0 ].data.IntTObj        );         \
    case CharTObjCode      : return func( v1, v2, format, arguments->elements[ 0 ].data.CharTObj       );         \
    case ShortTObjCode     : return func( v1, v2, format, arguments->elements[ 0 ].data.ShortTObj      );         \
    case LongTObjCode      : return func( v1, v2, format, arguments->elements[ 0 ].data.LongTObj       );         \
    case LLongTObjCode     : return func( v1, v2, format, arguments->elements[ 0 ].data.LLongTObj      );         \
    case IntMaxTObjCode    : return func( v1, v2, format, arguments->elements[ 0 ].data.IntMaxTObj     );         \
    case SizeTObjCode      : return func( v1, v2, format, arguments->elements[ 0 ].data.SizeTObj       );         \
    case PtrDiffTObjCode   : return func( v1, v2, format, arguments->elements[ 0 ].data.PtrDiffTObj    );         \
    case WIntTObjCode      : return func( v1, v2, format, arguments->elements[ 0 ].data.WIntTObj       );         \
    case FloatTObjCode     : return func( v1, v2, format, arguments->elements[ 0 ].data.FloatTObj      );         \
    case DoubleTObjCode    : return func( v1, v2, format, arguments->elements[ 0 ].data.DoubleTObj     );         \
    case LongDoubleTObjCode: return func( v1, v2, format, arguments->elements[ 0 ].data.LongDoubleTObj );         \
    case CStringCode       : return func( v1, v2, format, arguments->elements[ 0 ].data.CString        );         \
    case WStringCode       : return func( v1, v2, format, arguments->elements[ 0 ].data.WString        );         \
    case VoidTPtrObjCode   : return func( v1, v2, format, arguments->elements[ 0 ].data.VoidTPtrObj    );         \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type ); \
             return -1;                                                                                           \
}

#define Switch_1of1_3_ByValue( funcName, v1, v2, v3 )                                                             \
switch ( arguments->elements[ 0 ].type ) {                                                                        \
    case IntTObjCode       : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.IntTObj        );     \
    case CharTObjCode      : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.CharTObj       );     \
    case ShortTObjCode     : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.ShortTObj      );     \
    case LongTObjCode      : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.LongTObj       );     \
    case LLongTObjCode     : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.LLongTObj      );     \
    case IntMaxTObjCode    : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.IntMaxTObj     );     \
    case SizeTObjCode      : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.SizeTObj       );     \
    case PtrDiffTObjCode   : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.PtrDiffTObj    );     \
    case WIntTObjCode      : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.WIntTObj       );     \
    case FloatTObjCode     : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.FloatTObj      );     \
    case DoubleTObjCode    : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.DoubleTObj     );     \
    case LongDoubleTObjCode: return func( v1, v2, v3, format, arguments->elements[ 0 ].data.LongDoubleTObj );     \
    case CStringCode       : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.CString        );     \
    case WStringCode       : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.WString        );     \
    case VoidTPtrObjCode   : return func( v1, v2, v3, format, arguments->elements[ 0 ].data.VoidTPtrObj    );     \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type ); \
             return -1;                                                                                           \
}

#define Switch_2of2_0_ByValue( funcName, a0 )                                                                     \
switch ( arguments->elements[ 1 ].type ) {                                                                        \
    case IntTObjCode       : return func( format, a0, arguments->elements[ 1 ].data.IntTObj        );             \
    case CharTObjCode      : return func( format, a0, arguments->elements[ 1 ].data.CharTObj       );             \
    case ShortTObjCode     : return func( format, a0, arguments->elements[ 1 ].data.ShortTObj      );             \
    case LongTObjCode      : return func( format, a0, arguments->elements[ 1 ].data.LongTObj       );             \
    case LLongTObjCode     : return func( format, a0, arguments->elements[ 1 ].data.LLongTObj      );             \
    case IntMaxTObjCode    : return func( format, a0, arguments->elements[ 1 ].data.IntMaxTObj     );             \
    case SizeTObjCode      : return func( format, a0, arguments->elements[ 1 ].data.SizeTObj       );             \
    case PtrDiffTObjCode   : return func( format, a0, arguments->elements[ 1 ].data.PtrDiffTObj    );             \
    case WIntTObjCode      : return func( format, a0, arguments->elements[ 1 ].data.WIntTObj       );             \
    case FloatTObjCode     : return func( format, a0, arguments->elements[ 1 ].data.FloatTObj      );             \
    case DoubleTObjCode    : return func( format, a0, arguments->elements[ 1 ].data.DoubleTObj     );             \
    case LongDoubleTObjCode: return func( format, a0, arguments->elements[ 1 ].data.LongDoubleTObj );             \
    case CStringCode       : return func( format, a0, arguments->elements[ 1 ].data.CString        );             \
    case WStringCode       : return func( format, a0, arguments->elements[ 1 ].data.WString        );             \
    case VoidTPtrObjCode   : return func( format, a0, arguments->elements[ 1 ].data.VoidTPtrObj    );             \
    default: assertion( 0, #funcName " : arguments->elements[ 1 ].type is %d\n", arguments->elements[ 1 ].type ); \
             return -1;                                                                                           \
}

#define Switch_2of2_1_ByValue( funcName, v1, a0 )                                                                 \
switch ( arguments->elements[ 1 ].type ) {                                                                        \
    case IntTObjCode       : return func( v1, format, a0, arguments->elements[ 1 ].data.IntTObj        );         \
    case CharTObjCode      : return func( v1, format, a0, arguments->elements[ 1 ].data.CharTObj       );         \
    case ShortTObjCode     : return func( v1, format, a0, arguments->elements[ 1 ].data.ShortTObj      );         \
    case LongTObjCode      : return func( v1, format, a0, arguments->elements[ 1 ].data.LongTObj       );         \
    case LLongTObjCode     : return func( v1, format, a0, arguments->elements[ 1 ].data.LLongTObj      );         \
    case IntMaxTObjCode    : return func( v1, format, a0, arguments->elements[ 1 ].data.IntMaxTObj     );         \
    case SizeTObjCode      : return func( v1, format, a0, arguments->elements[ 1 ].data.SizeTObj       );         \
    case PtrDiffTObjCode   : return func( v1, format, a0, arguments->elements[ 1 ].data.PtrDiffTObj    );         \
    case WIntTObjCode      : return func( v1, format, a0, arguments->elements[ 1 ].data.WIntTObj       );         \
    case FloatTObjCode     : return func( v1, format, a0, arguments->elements[ 1 ].data.FloatTObj      );         \
    case DoubleTObjCode    : return func( v1, format, a0, arguments->elements[ 1 ].data.DoubleTObj     );         \
    case LongDoubleTObjCode: return func( v1, format, a0, arguments->elements[ 1 ].data.LongDoubleTObj );         \
    case CStringCode       : return func( v1, format, a0, arguments->elements[ 1 ].data.CString        );         \
    case WStringCode       : return func( v1, format, a0, arguments->elements[ 1 ].data.WString        );         \
    case VoidTPtrObjCode   : return func( v1, format, a0, arguments->elements[ 1 ].data.VoidTPtrObj    );         \
    default: assertion( 0, #funcName " : arguments->elements[ 1 ].type is %d\n", arguments->elements[ 1 ].type ); \
             return -1;                                                                                           \
}

#define Switch_2of2_2_ByValue( funcName, v1, v2, a0 )                                                             \
switch ( arguments->elements[ 1 ].type ) {                                                                        \
    case IntTObjCode       : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.IntTObj        );     \
    case CharTObjCode      : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.CharTObj       );     \
    case ShortTObjCode     : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.ShortTObj      );     \
    case LongTObjCode      : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.LongTObj       );     \
    case LLongTObjCode     : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.LLongTObj      );     \
    case IntMaxTObjCode    : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.IntMaxTObj     );     \
    case SizeTObjCode      : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.SizeTObj       );     \
    case PtrDiffTObjCode   : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.PtrDiffTObj    );     \
    case WIntTObjCode      : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.WIntTObj       );     \
    case FloatTObjCode     : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.FloatTObj      );     \
    case DoubleTObjCode    : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.DoubleTObj     );     \
    case LongDoubleTObjCode: return func( v1, v2, format, a0, arguments->elements[ 1 ].data.LongDoubleTObj );     \
    case CStringCode       : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.CString        );     \
    case WStringCode       : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.WString        );     \
    case VoidTPtrObjCode   : return func( v1, v2, format, a0, arguments->elements[ 1 ].data.VoidTPtrObj    );     \
    default: assertion( 0, #funcName " : arguments->elements[ 1 ].type is %d\n", arguments->elements[ 1 ].type ); \
             return -1;                                                                                           \
}

#define Switch_2of2_3_ByValue( funcName, v1, v2, v3, a0 )                                                         \
switch ( arguments->elements[ 1 ].type ) {                                                                        \
    case IntTObjCode       : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.IntTObj        ); \
    case CharTObjCode      : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.CharTObj       ); \
    case ShortTObjCode     : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.ShortTObj      ); \
    case LongTObjCode      : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.LongTObj       ); \
    case LLongTObjCode     : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.LLongTObj      ); \
    case IntMaxTObjCode    : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.IntMaxTObj     ); \
    case SizeTObjCode      : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.SizeTObj       ); \
    case PtrDiffTObjCode   : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.PtrDiffTObj    ); \
    case WIntTObjCode      : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.WIntTObj       ); \
    case FloatTObjCode     : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.FloatTObj      ); \
    case DoubleTObjCode    : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.DoubleTObj     ); \
    case LongDoubleTObjCode: return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.LongDoubleTObj ); \
    case CStringCode       : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.CString        ); \
    case WStringCode       : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.WString        ); \
    case VoidTPtrObjCode   : return func( v1, v2, v3, format, a0, arguments->elements[ 1 ].data.VoidTPtrObj    ); \
    default: assertion( 0, #funcName " : arguments->elements[ 1 ].type is %d\n", arguments->elements[ 1 ].type ); \
             return -1;                                                                                           \
}

#define Switch_1of2_0_ByValue( funcName )                                                                         \
switch ( arguments->elements[ 0 ].type ) {                                                                        \
    case IntTObjCode       : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.IntTObj        );     \
    case CharTObjCode      : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.CharTObj       );     \
    case ShortTObjCode     : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.ShortTObj      );     \
    case LongTObjCode      : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.LongTObj       );     \
    case LLongTObjCode     : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.LLongTObj      );     \
    case IntMaxTObjCode    : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.IntMaxTObj     );     \
    case SizeTObjCode      : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.SizeTObj       );     \
    case PtrDiffTObjCode   : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.PtrDiffTObj    );     \
    case WIntTObjCode      : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.WIntTObj       );     \
    case FloatTObjCode     : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.FloatTObj      );     \
    case DoubleTObjCode    : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.DoubleTObj     );     \
    case LongDoubleTObjCode: Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.LongDoubleTObj );     \
    case CStringCode       : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.CString        );     \
    case WStringCode       : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.WString        );     \
    case VoidTPtrObjCode   : Switch_2of2_0_ByValue( funcName, arguments->elements[ 0 ].data.VoidTPtrObj    );     \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type ); \
             return -1;                                                                                           \
}

#define Switch_1of2_1_ByValue( funcName, v1 )                                                                     \
switch ( arguments->elements[ 0 ].type ) {                                                                        \
    case IntTObjCode       : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.IntTObj        ); \
    case CharTObjCode      : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.CharTObj       ); \
    case ShortTObjCode     : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.ShortTObj      ); \
    case LongTObjCode      : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.LongTObj       ); \
    case LLongTObjCode     : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.LLongTObj      ); \
    case IntMaxTObjCode    : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.IntMaxTObj     ); \
    case SizeTObjCode      : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.SizeTObj       ); \
    case PtrDiffTObjCode   : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.PtrDiffTObj    ); \
    case WIntTObjCode      : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.WIntTObj       ); \
    case FloatTObjCode     : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.FloatTObj      ); \
    case DoubleTObjCode    : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.DoubleTObj     ); \
    case LongDoubleTObjCode: Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.LongDoubleTObj ); \
    case CStringCode       : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.CString        ); \
    case WStringCode       : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.WString        ); \
    case VoidTPtrObjCode   : Switch_2of2_1_ByValue( funcName, v1, arguments->elements[ 0 ].data.VoidTPtrObj    ); \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type ); \
             return -1;                                                                                           \
}

#define Switch_1of2_2_ByValue( funcName, v1, v2 )                                                                     \
switch ( arguments->elements[ 0 ].type ) {                                                                            \
    case IntTObjCode       : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.IntTObj        ); \
    case CharTObjCode      : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.CharTObj       ); \
    case ShortTObjCode     : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.ShortTObj      ); \
    case LongTObjCode      : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.LongTObj       ); \
    case LLongTObjCode     : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.LLongTObj      ); \
    case IntMaxTObjCode    : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.IntMaxTObj     ); \
    case SizeTObjCode      : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.SizeTObj       ); \
    case PtrDiffTObjCode   : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.PtrDiffTObj    ); \
    case WIntTObjCode      : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.WIntTObj       ); \
    case FloatTObjCode     : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.FloatTObj      ); \
    case DoubleTObjCode    : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.DoubleTObj     ); \
    case LongDoubleTObjCode: Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.LongDoubleTObj ); \
    case CStringCode       : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.CString        ); \
    case WStringCode       : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.WString        ); \
    case VoidTPtrObjCode   : Switch_2of2_2_ByValue( funcName, v1, v2, arguments->elements[ 0 ].data.VoidTPtrObj    ); \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type );     \
             return -1;                                                                                               \
}

#define Switch_1of2_3_ByValue( funcName, v1, v2, v3 )                                                                     \
switch ( arguments->elements[ 0 ].type ) {                                                                                \
    case IntTObjCode       : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.IntTObj        ); \
    case CharTObjCode      : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.CharTObj       ); \
    case ShortTObjCode     : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.ShortTObj      ); \
    case LongTObjCode      : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.LongTObj       ); \
    case LLongTObjCode     : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.LLongTObj      ); \
    case IntMaxTObjCode    : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.IntMaxTObj     ); \
    case SizeTObjCode      : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.SizeTObj       ); \
    case PtrDiffTObjCode   : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.PtrDiffTObj    ); \
    case WIntTObjCode      : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.WIntTObj       ); \
    case FloatTObjCode     : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.FloatTObj      ); \
    case DoubleTObjCode    : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.DoubleTObj     ); \
    case LongDoubleTObjCode: Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.LongDoubleTObj ); \
    case CStringCode       : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.CString        ); \
    case WStringCode       : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.WString        ); \
    case VoidTPtrObjCode   : Switch_2of2_3_ByValue( funcName, v1, v2, v3, arguments->elements[ 0 ].data.VoidTPtrObj    ); \
    default: assertion( 0, #funcName " : arguments->elements[ 0 ].type is %d\n", arguments->elements[ 0 ].type );         \
             return -1;                                                                                                   \
}

#define BodyWithSwitch_0_ByValue( funcName )                                     \
{                                                                                \
    if ( arguments->size == 0 ) {                                                \
        return func( format );                                                   \
    } else if ( arguments->size == 1 ) {                                         \
        Switch_1of1_0_ByValue( funcName )                                        \
    } else if ( arguments->size == 2 ) {                                         \
        Switch_1of2_0_ByValue( funcName )                                        \
    } else {                                                                     \
        assertion( 0, #funcName " : arguments->size is %d\n", arguments->size ); \
    }                                                                            \
} // funcName

#define BodyWithSwitch_1_ByValue( funcName, v1 )                                 \
{                                                                                \
    if ( arguments->size == 0 ) {                                                \
        return func( v1, format );                                               \
    } else if ( arguments->size == 1 ) {                                         \
        Switch_1of1_1_ByValue( funcName, v1 )                                    \
    } else if ( arguments->size == 2 ) {                                         \
        Switch_1of2_1_ByValue( funcName, v1 )                                    \
    } else {                                                                     \
        assertion( 0, #funcName " : arguments->size is %d\n", arguments->size ); \
    }                                                                            \
} // funcName

#define BodyWithSwitch_2_ByValue( funcName, v1, v2 )                             \
{                                                                                \
    if ( arguments->size == 0 ) {                                                \
        return func( v1, v2, format );                                           \
    } else if ( arguments->size == 1 ) {                                         \
        Switch_1of1_2_ByValue( funcName, v1, v2 )                                \
    } else if ( arguments->size == 2 ) {                                         \
        Switch_1of2_2_ByValue( funcName, v1, v2 )                                \
    } else {                                                                     \
        assertion( 0, #funcName " : arguments->size is %d\n", arguments->size ); \
    }                                                                            \
} // funcName

#define BodyWithSwitch_3_ByValue( funcName, v1, v2, v3 )                         \
{                                                                                \
    if ( arguments->size == 0 ) {                                                \
        return func( v1, v2, v3, format );                                       \
    } else if ( arguments->size == 1 ) {                                         \
        Switch_1of1_3_ByValue( funcName, v1, v2, v3 )                            \
    } else if ( arguments->size == 2 ) {                                         \
        Switch_1of2_3_ByValue( funcName, v1, v2, v3 )                            \
    } else {                                                                     \
        assertion( 0, #funcName " : arguments->size is %d\n", arguments->size ); \
    }                                                                            \
} // funcName

#define BodyWithSwitch_0_ByPtr( functionName )                                                          \
{                                                                                                       \
    if ( arguments->size == 0 ) { return func( format ); }                                              \
    assertion( arguments->size == 1, #functionName " : arguments->size is %d", arguments->size );       \
    switch ( arguments->elements[ 0 ].type ) {                                                          \
        case IntTObjCode       : return func( format, & arguments->elements[ 0 ].data.IntTObj        ); \
        case CharTObjCode      : return func( format, & arguments->elements[ 0 ].data.CharTObj       ); \
        case ShortTObjCode     : return func( format, & arguments->elements[ 0 ].data.ShortTObj      ); \
        case LongTObjCode      : return func( format, & arguments->elements[ 0 ].data.LongTObj       ); \
        case LLongTObjCode     : return func( format, & arguments->elements[ 0 ].data.LLongTObj      ); \
        case IntMaxTObjCode    : return func( format, & arguments->elements[ 0 ].data.IntMaxTObj     ); \
        case SizeTObjCode      : return func( format, & arguments->elements[ 0 ].data.SizeTObj       ); \
        case PtrDiffTObjCode   : return func( format, & arguments->elements[ 0 ].data.PtrDiffTObj    ); \
        case WIntTObjCode      : return func( format, & arguments->elements[ 0 ].data.WIntTObj       ); \
        case FloatTObjCode     : return func( format, & arguments->elements[ 0 ].data.FloatTObj      ); \
        case DoubleTObjCode    : return func( format, & arguments->elements[ 0 ].data.DoubleTObj     ); \
        case LongDoubleTObjCode: return func( format, & arguments->elements[ 0 ].data.LongDoubleTObj ); \
        case CStringCode       : return func( format,   arguments->elements[ 0 ].data.CString        ); \
        case WStringCode       : return func( format,   arguments->elements[ 0 ].data.WString        ); \
        case VoidTPtrObjCode   : return func( format, & arguments->elements[ 0 ].data.VoidTPtrObj    ); \
        default: assertion( 0, #functionName " : unsupported type" ); return -1;                        \
    }                                                                                                   \
} // functionName

#define BodyWithSwitch_1_ByPtr( functionName, v1 )                                                          \
{                                                                                                           \
    if ( arguments->size == 0 ) { return func( v1, format ); }                                              \
    assertion( arguments->size == 1, #functionName " : arguments->size is %d", arguments->size );           \
    switch ( arguments->elements[ 0 ].type ) {                                                              \
        case IntTObjCode       : return func( v1, format, & arguments->elements[ 0 ].data.IntTObj        ); \
        case CharTObjCode      : return func( v1, format, & arguments->elements[ 0 ].data.CharTObj       ); \
        case ShortTObjCode     : return func( v1, format, & arguments->elements[ 0 ].data.ShortTObj      ); \
        case LongTObjCode      : return func( v1, format, & arguments->elements[ 0 ].data.LongTObj       ); \
        case LLongTObjCode     : return func( v1, format, & arguments->elements[ 0 ].data.LLongTObj      ); \
        case IntMaxTObjCode    : return func( v1, format, & arguments->elements[ 0 ].data.IntMaxTObj     ); \
        case SizeTObjCode      : return func( v1, format, & arguments->elements[ 0 ].data.SizeTObj       ); \
        case PtrDiffTObjCode   : return func( v1, format, & arguments->elements[ 0 ].data.PtrDiffTObj    ); \
        case WIntTObjCode      : return func( v1, format, & arguments->elements[ 0 ].data.WIntTObj       ); \
        case FloatTObjCode     : return func( v1, format, & arguments->elements[ 0 ].data.FloatTObj      ); \
        case DoubleTObjCode    : return func( v1, format, & arguments->elements[ 0 ].data.DoubleTObj     ); \
        case LongDoubleTObjCode: return func( v1, format, & arguments->elements[ 0 ].data.LongDoubleTObj ); \
        case CStringCode       : return func( v1, format,   arguments->elements[ 0 ].data.CString        ); \
        case WStringCode       : return func( v1, format,   arguments->elements[ 0 ].data.WString        ); \
        case VoidTPtrObjCode   : return func( v1, format, & arguments->elements[ 0 ].data.VoidTPtrObj    ); \
        default: assertion( 0, #functionName " : unsupported type" ); return -1;                            \
    }                                                                                                       \
} // functionName

#define BodyWithSwitch_2_ByPtr( functionName, v1, v2 )                                                          \
{                                                                                                               \
    if ( arguments->size == 0 ) { return func( v1, v2, format ); }                                              \
    assertion( arguments->size == 1, #functionName " : arguments->size is %d", arguments->size );               \
    switch ( arguments->elements[ 0 ].type ) {                                                                  \
        case IntTObjCode       : return func( v1, v2, format, & arguments->elements[ 0 ].data.IntTObj        ); \
        case CharTObjCode      : return func( v1, v2, format, & arguments->elements[ 0 ].data.CharTObj       ); \
        case ShortTObjCode     : return func( v1, v2, format, & arguments->elements[ 0 ].data.ShortTObj      ); \
        case LongTObjCode      : return func( v1, v2, format, & arguments->elements[ 0 ].data.LongTObj       ); \
        case LLongTObjCode     : return func( v1, v2, format, & arguments->elements[ 0 ].data.LLongTObj      ); \
        case IntMaxTObjCode    : return func( v1, v2, format, & arguments->elements[ 0 ].data.IntMaxTObj     ); \
        case SizeTObjCode      : return func( v1, v2, format, & arguments->elements[ 0 ].data.SizeTObj       ); \
        case PtrDiffTObjCode   : return func( v1, v2, format, & arguments->elements[ 0 ].data.PtrDiffTObj    ); \
        case WIntTObjCode      : return func( v1, v2, format, & arguments->elements[ 0 ].data.WIntTObj       ); \
        case FloatTObjCode     : return func( v1, v2, format, & arguments->elements[ 0 ].data.FloatTObj      ); \
        case DoubleTObjCode    : return func( v1, v2, format, & arguments->elements[ 0 ].data.DoubleTObj     ); \
        case LongDoubleTObjCode: return func( v1, v2, format, & arguments->elements[ 0 ].data.LongDoubleTObj ); \
        case CStringCode       : return func( v1, v2, format,   arguments->elements[ 0 ].data.CString        ); \
        case WStringCode       : return func( v1, v2, format,   arguments->elements[ 0 ].data.WString        ); \
        case VoidTPtrObjCode   : return func( v1, v2, format, & arguments->elements[ 0 ].data.VoidTPtrObj    ); \
        default: assertion( 0, #functionName " : unsupported type" ); return -1;                                \
    }                                                                                                           \
} // functionName

#define BodyWithSwitch_3_ByPtr( functionName, v1, v2, v3 )                                                          \
{                                                                                                                   \
    if ( arguments->size == 0 ) { return func( v1, v2, v3, format ); }                                              \
    assertion( arguments->size == 1, #functionName " : arguments->size is %d", arguments->size );                   \
    switch ( arguments->elements[ 0 ].type ) {                                                                      \
        case IntTObjCode       : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.IntTObj        ); \
        case CharTObjCode      : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.CharTObj       ); \
        case ShortTObjCode     : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.ShortTObj      ); \
        case LongTObjCode      : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.LongTObj       ); \
        case LLongTObjCode     : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.LLongTObj      ); \
        case IntMaxTObjCode    : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.IntMaxTObj     ); \
        case SizeTObjCode      : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.SizeTObj       ); \
        case PtrDiffTObjCode   : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.PtrDiffTObj    ); \
        case WIntTObjCode      : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.WIntTObj       ); \
        case FloatTObjCode     : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.FloatTObj      ); \
        case DoubleTObjCode    : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.DoubleTObj     ); \
        case LongDoubleTObjCode: return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.LongDoubleTObj ); \
        case CStringCode       : return func( v1, v2, v3, format,   arguments->elements[ 0 ].data.CString        ); \
        case WStringCode       : return func( v1, v2, v3, format,   arguments->elements[ 0 ].data.WString        ); \
        case VoidTPtrObjCode   : return func( v1, v2, v3, format, & arguments->elements[ 0 ].data.VoidTPtrObj    ); \
        default: assertion( 0, #functionName " : unsupported type" ); return -1;                                    \
    }                                                                                                               \
} // functionName

// print, warn, printw
// void *             , char * formar, ...
//                      char * formar, ...
// char *, size_t     , char * formar, ...
// 0     , size_t     , char * formar, ...
// char *             , char * formar, ...
//         int        , char * formar, ...
//         int   , int, char * formar, ...
// void *, int   , int, char * formar, ...

static int functionTypedValuesCall_print_VoidTPtrObj( int (*func)(), void * ptr, char * format, TypedList * arguments )
BodyWithSwitch_1_ByValue( functionTypedValuesCall_print_VoidTPtrObj, ptr )

static int functionTypedValuesCall_print_Empty( int (*func)(), char * format, TypedList * arguments )
BodyWithSwitch_0_ByValue( functionTypedValuesCall_print_Empty )

static int functionTypedValuesCall_print_CStringSizeTObj
               ( int (*func)(), char * s, size_t n, char * format, TypedList * arguments )
BodyWithSwitch_2_ByValue( functionTypedValuesCall_print_CStringSizeTObj, s, n )

static int functionTypedValuesCall_print_CString( int (*func)(), char * s, char * format, TypedList * arguments )
BodyWithSwitch_1_ByValue( functionTypedValuesCall_print_CString, s )

static int functionTypedValuesCall_print_IntTObj( int (*func)(), int fd, char * format, TypedList * arguments )
BodyWithSwitch_1_ByValue( functionTypedValuesCall_print_IntTObj, fd )

static int functionTypedValuesCall_print_IntTObjIntTObj
               ( int (*func)(), int y, int x, char * format, TypedList * arguments )
BodyWithSwitch_2_ByValue( functionTypedValuesCall_print_IntTObjIntTObj, y, x )

static int functionTypedValuesCall_print_VoidTPtrObjIntTObjIntTObj
               ( int (*func)(), void * ptr, int y, int x, char * format, TypedList * arguments )
BodyWithSwitch_3_ByValue( functionTypedValuesCall_print_VoidTPtrObjIntTObjIntTObj, ptr, y, x )

// scan, scanw
// void *          , char * formar, ...
//                   char * formar, ...
// char *          , char * formar, ...
//         int, int, char * formar, ...
// void *, int, int, char * formar, ...

static int functionTypedValuesCall_scan_VoidTPtrObj( int (*func)(), void * ptr, char * format, TypedList * arguments )
BodyWithSwitch_1_ByPtr( functionTypedValuesCall_scan_VoidTPtrObj, ptr )

static int functionTypedValuesCall_scan_Empty( int (*func)(), char * format, TypedList * arguments )
BodyWithSwitch_0_ByPtr( functionTypedValuesCall_scan_Empty )

static int functionTypedValuesCall_scan_CString( int (*func)(), char * s, char * format, TypedList * arguments )
BodyWithSwitch_1_ByPtr( functionTypedValuesCall_scan_CString, s )

static int functionTypedValuesCall_scan_IntTObjIntTObj( int (*func)(), int y, int x, char * format, TypedList * arguments )
BodyWithSwitch_2_ByPtr( functionTypedValuesCall_scan_IntTObjIntTObj, y, x )

static int functionTypedValuesCall_scan_VoidTPtrObjIntTObjIntTObj
               ( int (*func)(), void * ptr, int y, int x, char * format, TypedList * arguments )
BodyWithSwitch_3_ByPtr( functionTypedValuesCall_scan_VoidTPtrObjIntTObjIntTObj, ptr, y, x )

// wprint
// void *                , wchar_t * formar, ...
// wchar_t * ws, size_t n, wchar_t * formar, ...
// 0           , size_t n, wchar_t * formar, ...
//                         wchar_t * formar, ...

static int functionTypedValuesCall_wprint_VoidTPtrObj( int (*func)(), void * ptr, wchar_t * format, TypedList * arguments )
BodyWithSwitch_1_ByValue( functionTypedValuesCall_wprint_VoidTPtrObj, ptr )

static int functionTypedValuesCall_wprint_WStringSizeTObj
               ( int (*func)(), wchar_t * ws, size_t n, wchar_t * format, TypedList * arguments )
BodyWithSwitch_2_ByValue( functionTypedValuesCall_wprint_WStringSizeTObj, ws, n )

static int functionTypedValuesCall_wprint_Empty( int (*func)(), wchar_t * format, TypedList * arguments )
BodyWithSwitch_0_ByValue( functionTypedValuesCall_wprint_Empty )

// wscan
// void *       wchar_t * formar, ...
// wchar_t * s, wchar_t * formar, ...
//              wchar_t * formar, ...

static int functionTypedValuesCall_wscan_VoidTPtrObj( int (*func)(), void * ptr, wchar_t * format, TypedList * arguments )
BodyWithSwitch_1_ByPtr( functionTypedValuesCall_wscan_VoidTPtrObj, ptr )

static int functionTypedValuesCall_wscan_WString( int (*func)(), wchar_t * s, wchar_t * format, TypedList * arguments )
BodyWithSwitch_1_ByPtr( functionTypedValuesCall_wscan_WString, s )

static int functionTypedValuesCall_wscan_Empty( int (*func)(), wchar_t * format, TypedList * arguments )
BodyWithSwitch_0_ByPtr( functionTypedValuesCall_wscan_Empty )

#undef Switch_1of1_0_ByValue
#undef Switch_1of1_1_ByValue
#undef Switch_1of1_2_ByValue
#undef Switch_1of1_3_ByValue
#undef Switch_2of2_0_ByValue
#undef Switch_2of2_1_ByValue
#undef Switch_2of2_2_ByValue
#undef Switch_2of2_3_ByValue
#undef Switch_1of2_0_ByValue
#undef Switch_1of2_1_ByValue
#undef Switch_1of2_2_ByValue
#undef Switch_1of2_3_ByValue
#undef BodyWithSwitch_0_ByValue
#undef BodyWithSwitch_1_ByValue
#undef BodyWithSwitch_2_ByValue
#undef BodyWithSwitch_3_ByValue
#undef BodyWithSwitch_0_ByPtr
#undef BodyWithSwitch_1_ByPtr
#undef BodyWithSwitch_2_ByPtr
#undef BodyWithSwitch_3_ByPtr

int functionTypedValuesCall( long functionAsLong, TypedList * arguments ) {
    TypedList shiftedArguments;
    int (*func)();
    //ta_debug_printf( "functionTypedValuesCall\n" );
    //printTypedList( arguments );
    func = (int (*)())functionAsLong;
    // print
    if ( ( functionAsLong == (long)asprintf ) || ( functionAsLong == (long)vasprintfDotsShell ) ||
         ( functionAsLong == (long)fprintf  ) || ( functionAsLong == (long)vfprintfDotsShell  )
       ) {
        void * ptr    = arguments->elements[ 0 ].data.VoidTPtrObj;
        char * format = arguments->elements[ 1 ].data.CString    ;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_print_VoidTPtrObj( func, ptr, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)printf ) || ( functionAsLong == (long)vprintfDotsShell ) ) {
        char * format = arguments->elements[ 0 ].data.CString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        return functionTypedValuesCall_print_Empty( func, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)snprintf ) || ( functionAsLong == (long)vsnprintfDotsShell ) ) {
        char   * s      = arguments->elements[ 0 ].data.CString ; // or 0 as LongTObj
        size_t   n      = arguments->elements[ 1 ].data.SizeTObj;
        char   * format = arguments->elements[ 2 ].data.CString ;
        shiftedArguments.size     = arguments->size     - 3;
        shiftedArguments.elements = arguments->elements + 3;
        return functionTypedValuesCall_print_CStringSizeTObj( func, s, n, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)sprintf ) || ( functionAsLong == (long)vsprintfDotsShell ) ) {
        char * s      = arguments->elements[ 0 ].data.CString;
        char * format = arguments->elements[ 1 ].data.CString;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_print_CString( func, s, format, & shiftedArguments );
    } else if ( functionAsLong == (long)vdprintfDotsShell ) {
        int    fd     = arguments->elements[ 0 ].data.IntTObj;
        char * format = arguments->elements[ 1 ].data.CString;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_print_IntTObj( func, fd, format, & shiftedArguments );
    // scan
    } else if ( ( functionAsLong == (long)fscanf ) || ( functionAsLong == (long)vfscanfDotsShell ) ) {
        void * ptr    = arguments->elements[ 0 ].data.VoidTPtrObj;
        char * format = arguments->elements[ 1 ].data.CString    ;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_scan_VoidTPtrObj( func, ptr, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)scanf ) || ( functionAsLong == (long)vscanfDotsShell ) ) {
        char * format = arguments->elements[ 0 ].data.CString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        return functionTypedValuesCall_scan_Empty( func, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)sscanf ) || ( functionAsLong == (long)vsscanfDotsShell ) ) {
        char * s      = arguments->elements[ 0 ].data.CString;
        char * format = arguments->elements[ 1 ].data.CString;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_scan_CString( func, s, format, & shiftedArguments );
    // wprint
    } else if ( ( functionAsLong == (long)fwprintf ) || ( functionAsLong == (long)vfwprintfDotsShell ) ) {
        void    * ptr    = arguments->elements[ 0 ].data.VoidTPtrObj;
        wchar_t * format = arguments->elements[ 1 ].data.WString    ;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_wprint_VoidTPtrObj( func, ptr, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)swprintf ) || ( functionAsLong == (long)vswprintfDotsShell ) ) {
        wchar_t * ws     = arguments->elements[ 0 ].data.WString ; // or 0 as LongTObj
        size_t    n      = arguments->elements[ 1 ].data.SizeTObj;
        wchar_t * format = arguments->elements[ 2 ].data.WString ;
        shiftedArguments.size     = arguments->size     - 3;
        shiftedArguments.elements = arguments->elements + 3;
        return functionTypedValuesCall_wprint_WStringSizeTObj( func, ws, n, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)wprintf ) || ( functionAsLong == (long)vwprintfDotsShell ) ) {
        wchar_t * format = arguments->elements[ 0 ].data.WString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        return functionTypedValuesCall_wprint_Empty( func, format, & shiftedArguments );
    // wscan
    } else if ( ( functionAsLong == (long)fwscanf ) || ( functionAsLong == (long)vfwscanfDotsShell ) ) {
        void    * ptr    = arguments->elements[ 0 ].data.VoidTPtrObj;
        wchar_t * format = arguments->elements[ 1 ].data.WString    ;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_wscan_VoidTPtrObj( func, ptr, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)swscanf ) || ( functionAsLong == (long)vswscanfDotsShell ) ) {
        wchar_t * s      = arguments->elements[ 0 ].data.WString;
        wchar_t * format = arguments->elements[ 1 ].data.WString;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_wscan_WString( func, s, format, & shiftedArguments );
    } else if ( ( functionAsLong == (long)wscanf ) || ( functionAsLong == (long)vwscanfDotsShell ) ) {
        wchar_t * format = arguments->elements[ 0 ].data.WString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        return functionTypedValuesCall_wscan_Empty( func, format, & shiftedArguments );
    // warn
    } else if ( ( functionAsLong == (long)warn ) || ( functionAsLong == (long)warnx ) ) {
        char * fmt = arguments->elements[ 0 ].data.CString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        shiftedArguments.size--; // last element is (was) stderrAsFile
        return functionTypedValuesCall_print_Empty( func, fmt, & shiftedArguments );
    // ncurses printw
    } else if ( functionAsLong == (long)mvprintw ) {
        int    y   = arguments->elements[ 0 ].data.IntTObj;
        int    x   = arguments->elements[ 1 ].data.IntTObj;
        char * fmt = arguments->elements[ 2 ].data.CString;
        shiftedArguments.size     = arguments->size     - 3;
        shiftedArguments.elements = arguments->elements + 3;
        return functionTypedValuesCall_print_IntTObjIntTObj( func, y, x, fmt, & shiftedArguments );
    } else if ( functionAsLong == (long)mvwprintw ) {
        void * win = arguments->elements[ 0 ].data.VoidTPtrObj;
        int    y   = arguments->elements[ 1 ].data.IntTObj;
        int    x   = arguments->elements[ 2 ].data.IntTObj;
        char * fmt = arguments->elements[ 3 ].data.CString;
        shiftedArguments.size     = arguments->size     - 4;
        shiftedArguments.elements = arguments->elements + 4;
        return functionTypedValuesCall_print_VoidTPtrObjIntTObjIntTObj( func, win, y, x, fmt, & shiftedArguments );
    } else if ( functionAsLong == (long)printw ) {
        char * fmt = arguments->elements[ 0 ].data.CString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        return functionTypedValuesCall_print_Empty( func, fmt, & shiftedArguments );
    } else if ( ( functionAsLong == (long)wprintw ) || ( functionAsLong == (long)vw_printwDotsShell ) ||
                                                       ( functionAsLong == (long)vwprintwDotsShell  )
              ) {
        void * win = arguments->elements[ 0 ].data.VoidTPtrObj;
        char * fmt = arguments->elements[ 1 ].data.CString;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_print_VoidTPtrObj( func, win, fmt, & shiftedArguments );
    // ncurses scanw
    } else if ( functionAsLong == (long)mvscanw ) {
        int    y   = arguments->elements[ 0 ].data.IntTObj;
        int    x   = arguments->elements[ 1 ].data.IntTObj;
        char * fmt = arguments->elements[ 2 ].data.CString;
        shiftedArguments.size     = arguments->size     - 3;
        shiftedArguments.elements = arguments->elements + 3;
        return functionTypedValuesCall_scan_IntTObjIntTObj( func, y, x, fmt, & shiftedArguments );
    } else if ( functionAsLong == (long)mvwscanw ) {
        void * win = arguments->elements[ 0 ].data.VoidTPtrObj;
        int    y   = arguments->elements[ 1 ].data.IntTObj;
        int    x   = arguments->elements[ 2 ].data.IntTObj;
        char * fmt = arguments->elements[ 3 ].data.CString;
        shiftedArguments.size     = arguments->size     - 4;
        shiftedArguments.elements = arguments->elements + 4;
        return functionTypedValuesCall_scan_VoidTPtrObjIntTObjIntTObj( func, win, y, x, fmt, & shiftedArguments );
    } else if ( functionAsLong == (long)scanw ) {
        char * fmt = arguments->elements[ 0 ].data.CString;
        shiftedArguments.size     = arguments->size     - 1;
        shiftedArguments.elements = arguments->elements + 1;
        return functionTypedValuesCall_scan_Empty( func, fmt, & shiftedArguments );
    } else if ( ( functionAsLong == (long)wscanw ) || ( functionAsLong == (long)vw_scanwDotsShell ) ||
                                                      ( functionAsLong == (long)vwscanwDotsShell  )
              ) {
        void * win = arguments->elements[ 0 ].data.VoidTPtrObj;
        char * fmt = arguments->elements[ 1 ].data.CString;
        shiftedArguments.size     = arguments->size     - 2;
        shiftedArguments.elements = arguments->elements + 2;
        return functionTypedValuesCall_scan_VoidTPtrObj( func, win, fmt, & shiftedArguments );
    // unknown function
    } else {
        assertion( 0, "functionTypedValuesCall : unknown function" );
        return -1;
    }
} // functionTypedValuesCall

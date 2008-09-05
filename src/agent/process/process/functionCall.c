#include <err.h>
#include "common/agent.h"

int functionLongValuesCall( int sizeA, long * pa ) {
    int (*func)();
    int res;
    // kpm
    char buffer[ 1024 ];
    if ( sizeof( double ) == sizeof( long ) ) { sprintf( buffer, "[%f]\n", * (double *)& pa[ 2 ] ); }
    if ( 0 ) {
        int i;
        for ( i = 0; i < sizeA; i++ ) {
            ta_debug_printf( "functionLongValuesCall : pa[ %i ] is [%016lX]\n", i, pa[ i ] );
        }
        ta_debug_printf( "functionLongValuesCall : pa[ 0 ] is %swarn\n", pa[ 0 ] == (long)warn ? "" : "not " );
        if ( pa[ 0 ] == (long)warn ) {
            //ta_debug_printf( "functionLongValuesCall : 12.7777777 is [%016lX]\n", 12.7777777 );
            ta_debug_printf( "functionLongValuesCall : (char *)pa[ 1 ] is [%s]\n", (char *)pa[ 1 ] );
            ta_debug_printf( "functionLongValuesCall : pa[ 2 ] is [%f]\n", pa[ 2 ] );
            ta_debug_printf( "functionLongValuesCall : (char *)pa[ 3 ] is [%s]\n", (char *)pa[ 3 ] );
        }
    } // if
    if ( sizeA < 2 ) { return -1; }
    func = (int (*)())pa[ 0 ];
    switch ( sizeA - 1 ) {
        case  1: res = (*func)( pa[  1 ]                                                                        ); break;
        case  2: res = (*func)( pa[  1 ], pa[  2 ]                                                              ); break;
        case  3: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ]                                                    ); break;
        case  4: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ]                                          ); break;
        case  5: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ]                                ); break;
        case  6: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ]                      ); break;
        case  7: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ]            ); break;
        case  8: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ]  ); break;
        case  9: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ]                                                                        ); break;
        case 10: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ]                                                              ); break;
        case 11: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ]                                                    ); break;
        case 12: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ]                                          ); break;
        case 13: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ]                                ); break;
        case 14: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ]                      ); break;
        case 15: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ]            ); break;
        case 16: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ]  ); break;
        case 17: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ]                                                                        ); break;
        case 18: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ]                                                              ); break;
        case 19: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ]                                                    ); break;
        case 20: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ]                                          ); break;
        case 21: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ]                                ); break;
        case 22: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ]                      ); break;
        case 23: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ]            ); break;
        case 24: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ]  ); break;
        case 25: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ]                                                                        ); break;
        case 26: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ]                                                              ); break;
        case 27: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ]                                                    ); break;
        case 28: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ]                                          ); break;
        case 29: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ]                                ); break;
        case 30: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ]                      ); break;
        case 31: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ]            ); break;
        case 32: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ]  ); break;
        case 33: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ]                                                                        ); break;
        case 34: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ]                                                              ); break;
        case 35: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ]                                                    ); break;
        case 36: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ]                                          ); break;
        case 37: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ]                                ); break;
        case 38: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ]                      ); break;
        case 39: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ]            ); break;
        case 40: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ]  ); break;
        case 41: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ]                                                                        ); break;
        case 42: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ]                                                              ); break;
        case 43: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ]                                                    ); break;
        case 44: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ]                                          ); break;
        case 45: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ]                                ); break;
        case 46: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ]                      ); break;
        case 47: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ]            ); break;
        case 48: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ]  ); break;
        case 49: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ]                                                                        ); break;
        case 50: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ]                                                              ); break;
        case 51: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ]                                                    ); break;
        case 52: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ]                                          ); break;
        case 53: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ]                                ); break;
        case 54: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ]                      ); break;
        case 55: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ]            ); break;
        case 56: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ]  ); break;
        case 57: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ]                                                                        ); break;
        case 58: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ]                                                              ); break;
        case 59: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ], pa[ 59 ]                                                    ); break;
        case 60: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ], pa[ 59 ], pa[ 60 ]                                          ); break;
        case 61: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ], pa[ 59 ], pa[ 60 ], pa[ 61 ]                                ); break;
        case 62: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ], pa[ 59 ], pa[ 60 ], pa[ 61 ], pa[ 62 ]                      ); break;
        case 63: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ], pa[ 59 ], pa[ 60 ], pa[ 61 ], pa[ 62 ], pa[ 63 ]            ); break;
        case 64: res = (*func)( pa[  1 ], pa[  2 ], pa[  3 ], pa[  4 ], pa[  5 ], pa[  6 ], pa[  7 ], pa[  8 ],
                                pa[  9 ], pa[ 10 ], pa[ 11 ], pa[ 12 ], pa[ 13 ], pa[ 14 ], pa[ 15 ], pa[ 16 ],
                                pa[ 17 ], pa[ 18 ], pa[ 19 ], pa[ 20 ], pa[ 21 ], pa[ 22 ], pa[ 23 ], pa[ 24 ],
                                pa[ 25 ], pa[ 26 ], pa[ 27 ], pa[ 28 ], pa[ 29 ], pa[ 30 ], pa[ 31 ], pa[ 32 ],
                                pa[ 33 ], pa[ 34 ], pa[ 35 ], pa[ 36 ], pa[ 37 ], pa[ 38 ], pa[ 39 ], pa[ 40 ],
                                pa[ 41 ], pa[ 42 ], pa[ 43 ], pa[ 44 ], pa[ 45 ], pa[ 46 ], pa[ 47 ], pa[ 48 ],
                                pa[ 49 ], pa[ 50 ], pa[ 51 ], pa[ 52 ], pa[ 53 ], pa[ 54 ], pa[ 55 ], pa[ 56 ],
                                pa[ 57 ], pa[ 58 ], pa[ 59 ], pa[ 60 ], pa[ 61 ], pa[ 62 ], pa[ 63 ], pa[ 64 ]  ); break;
        default: res = -1; break;
    } // switch sizeA - 1
    return res;
} // functionLongValuesCall

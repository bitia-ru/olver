#ifndef __COVERAGE_H__
#define __COVERAGE_H__

#include "utils/boolean.h"

typedef const char* CoverageText;

typedef int CoverageElement;

typedef enum
{ PRIMARY_COVERAGE
, DOMAIN_VARIATION_COVERAGE
, MULTIPLICATION_COVERAGE
}
COVERAGE_KIND;

typedef struct _CoverageDesc
{
    COVERAGE_KIND kind;
    // the total number of elements in this coverage
    // irrespective of possible presence of filter expression.
    // for primary coverages this field denotes the length
    // of the 'data' array
    int size;
    // the number of direct base coverages for this coverage
    // for derived coverages this field denotes the length
    // of the 'data' array.
    // for primary coverages this field should be 0.
    // for coverages of 'DOMAIN_VARIATION' kind this field should be 1.
    int base_num;
    int order;
    // this flag is true if the coverage is global coverage, i.e. is defined
    // outside any specification function.
    bool is_global;
    int last_trace_id;
    CoverageText name;
    CoverageElement (*calc)(  );
    bool (*filter)( CoverageElement );
    const void* data[];
}
CoverageDesc;

extern int _CE_OUT_OF_COVERAGE;

const CoverageDesc* cov_component( const CoverageDesc* cov_desc, int a );

CoverageElement ce_product( const CoverageDesc* cov_desc, ... );

CoverageElement ce_coord( const CoverageDesc* cov_desc
                        , CoverageElement element
                        , int axis
                        , CoverageDesc** p_prim_cov_desc
                        );

CoverageText ce_txt( const CoverageDesc* cov_desc, CoverageElement elem );

bool isElementInCoverage( const CoverageDesc* cov_desc, int element );

void traceReachedCoverageElement( CoverageDesc* cov_desc, int element );

void traceCoverageStructure( CoverageDesc* cov_desc );

#endif // __COVERAGE_H__

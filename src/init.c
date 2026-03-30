#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

/* declare your C function */
extern void estdep(double *, double *, int *, double *, double *);

/* register routines */
static const R_CMethodDef CEntries[] = {
    {"estdep", (DL_FUNC) &estdep, 5},
    {NULL, NULL, 0}
};

/* initialization */
void R_init_Blestdiscrete(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"

bool_t
xdr_args (XDR *xdrs, args *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->num1))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->num2))
		 return FALSE;
	return TRUE;
}
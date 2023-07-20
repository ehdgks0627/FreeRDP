#include <winpr/crt.h>
#include <winpr/print.h>

#include "../../ncrush.h"

static int test_NCrushDecompressBells(const BYTE* pSrcData, UINT32 SrcSize)
{
	BOOL rc = FALSE;
	int status;
	UINT32 Flags;
	UINT32 DstSize;
	UINT32 expectedSize;
	const BYTE* pDstData = NULL;
	NCRUSH_CONTEXT* ncrush = ncrush_context_new(FALSE);

	Flags = PACKET_COMPRESSED | 2;
	status = ncrush_decompress(ncrush, pSrcData, SrcSize, &pDstData, &DstSize, Flags);
	
	ncrush_context_free(ncrush);
    return status >= 0 ? 0 : -1;
}


int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
{
    if (Size <= 4) {
        return 0;
    }
	return test_NCrushDecompressBells(Data, Size);
}
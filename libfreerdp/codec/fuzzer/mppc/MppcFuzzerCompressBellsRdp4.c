#include <winpr/crt.h>
#include <winpr/print.h>
#include <winpr/bitstream.h>

#include <freerdp/freerdp.h>
#include <freerdp/log.h>
#include "../../mppc.h"

static int test_MppcCompressBellsRdp4(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	BYTE OutputBuffer[65536] = { 0 };
	UINT32 DstSize = sizeof(OutputBuffer);
	const BYTE* pDstData = NULL;
	MPPC_CONTEXT* mppc = mppc_context_new(0, TRUE);

	status = mppc_compress(mppc, pSrcData, SrcSize, OutputBuffer, &pDstData, &DstSize, &Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
{
	if (Size == 0)
	{
		return 0;
	}
	return test_MppcCompressBellsRdp4(Data, Size);
}

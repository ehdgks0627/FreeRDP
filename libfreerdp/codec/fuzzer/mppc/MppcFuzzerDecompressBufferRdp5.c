#include <winpr/crt.h>
#include <winpr/print.h>
#include <winpr/bitstream.h>

#include <freerdp/freerdp.h>
#include <freerdp/log.h>
#include "../../mppc.h"

static int test_MppcDecompressBufferRdp5(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	UINT32 DstSize;
	MPPC_CONTEXT* mppc;
	const BYTE* pDstData = NULL;
	mppc = mppc_context_new(1, FALSE);

	if (!mppc)
		return -1;

	Flags = PACKET_AT_FRONT | PACKET_COMPRESSED | 1;
	status = mppc_decompress(mppc, pSrcData, SrcSize, &pDstData, &DstSize, Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size)
{
	return test_MppcDecompressBufferRdp5(Data, Size);
}

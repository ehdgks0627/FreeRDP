#include <libfreerdp/codec/mppc.h>
#include "mppc_fuzzer.h"


#include <winpr/crt.h>
#include <winpr/print.h>
#include <winpr/bitstream.h>

#include <freerdp/freerdp.h>
#include <freerdp/log.h>


static int test_MppcCompressBellsRdp5(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	BYTE OutputBuffer[65536] = { 0 };
	UINT32 DstSize = sizeof(OutputBuffer);
	const BYTE* pDstData = NULL;

	MPPC_CONTEXT* mppc = mppc_context_new(1, TRUE);

	if (!mppc)
		return -1;

	status = mppc_compress(mppc, pSrcData, SrcSize, OutputBuffer, &pDstData, &DstSize, &Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

static int test_MppcCompressBellsRdp4(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	BYTE OutputBuffer[65536] = { 0 };
	UINT32 DstSize = sizeof(OutputBuffer);
	const BYTE* pDstData = NULL;
	MPPC_CONTEXT* mppc = mppc_context_new(0, TRUE);

	if (!mppc)
		return -1;

	status = mppc_compress(mppc, pSrcData, SrcSize, OutputBuffer, &pDstData, &DstSize, &Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

static int test_MppcCompressIslandRdp5(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	BYTE OutputBuffer[65536] = { 0 };
	UINT32 DstSize = sizeof(OutputBuffer);
	const BYTE* pDstData = NULL;
	MPPC_CONTEXT* mppc = mppc_context_new(1, TRUE);

	if (!mppc)
		return -1;

	status = mppc_compress(mppc, pSrcData, SrcSize, OutputBuffer, &pDstData, &DstSize, &Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

static int test_MppcCompressBufferRdp5(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	BYTE OutputBuffer[65536] = { 0 };
	UINT32 DstSize = sizeof(OutputBuffer);

	const BYTE* pDstData = NULL;
	MPPC_CONTEXT* mppc = mppc_context_new(1, TRUE);

	if (!mppc)
		return -1;

	status = mppc_compress(mppc, pSrcData, SrcSize, OutputBuffer, &pDstData, &DstSize, &Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  	if (test_MppcCompressIslandRdp5(Data, Size) < 0)
		return -1;

	if (test_MppcCompressBellsRdp5(Data, Size) < 0)
		return -1;

	if (test_MppcCompressBellsRdp4(Data, Size) < 0)
		return -1;

	if (test_MppcCompressBufferRdp5(Data, Size) < 0)
		return -1;

	return 0;
}

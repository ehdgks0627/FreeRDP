#include <libfreerdp/codec/mppc.h>
#include "mppc_fuzzer.h"


#include <winpr/crt.h>
#include <winpr/print.h>
#include <winpr/bitstream.h>

#include <freerdp/freerdp.h>
#include <freerdp/log.h>

static int test_MppcDecompressBellsRdp5(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	const BYTE* pSrcData;
	UINT32 SrcSize;
	UINT32 DstSize;
	MPPC_CONTEXT* mppc;
	UINT32 expectedSize;
	const BYTE* pDstData = NULL;
	mppc = mppc_context_new(1, FALSE);

	if (!mppc)
		return -1;

	Flags = PACKET_AT_FRONT | PACKET_COMPRESSED | 1;
	status = mppc_decompress(mppc, pSrcData, SrcSize, &pDstData, &DstSize, Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

static int test_MppcDecompressBellsRdp4(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	const BYTE* pSrcData;
	UINT32 SrcSize;
	UINT32 DstSize;
	MPPC_CONTEXT* mppc;
	UINT32 expectedSize;
	const BYTE* pDstData = NULL;
	mppc = mppc_context_new(0, FALSE);

	if (!mppc)
		return -1;

	Flags = PACKET_AT_FRONT | PACKET_COMPRESSED | 0;
	status = mppc_decompress(mppc, pSrcData, SrcSize, &pDstData, &DstSize, Flags);

	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

static int test_MppcDecompressBufferRdp5(const BYTE* pSrcData, const UINT32 SrcSize)
{
	int status;
	UINT32 Flags;
	const BYTE* pSrcData;
	UINT32 SrcSize;
	UINT32 DstSize;
	MPPC_CONTEXT* mppc;
	const BYTE* pDstData = NULL;
	mppc = mppc_context_new(1, FALSE);

	if (!mppc)
		return -1;

	Flags = PACKET_AT_FRONT | PACKET_COMPRESSED | 1;
	status = mppc_decompress(mppc, pSrcData, SrcSize, &pDstData, &DstSize, Flags);
:
	mppc_context_free(mppc);
	return status >= 0 ? 0 : -1;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
	if (test_MppcDecompressBellsRdp5(Data, Size) < 0)
		return -1;

	if (test_MppcDecompressBellsRdp4(Data, Size) < 0)
		return -1;

	if (test_MppcDecompressBufferRdp5(Data, Size) < 0)
		return -1;

	return 0;
  return 0;  // Values other than 0 and -1 are reserved for future use.
}

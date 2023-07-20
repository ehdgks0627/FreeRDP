/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * MPPC Bulk Data Compression
 *
 * Copyright 2014 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_MPPC_H
#define FREERDP_MPPC_H

#include <freerdp/api.h>
#include <freerdp/types.h>

#include <winpr/bitstream.h>

#include <freerdp/codec/bulk.h>

typedef struct s_MPPC_CONTEXT MPPC_CONTEXT;

#ifdef __cplusplus
extern "C"
{
#endif

	int mppc_compress(MPPC_CONTEXT* mppc, const BYTE* pSrcData, UINT32 SrcSize,
	                                BYTE* pDstBuffer, const BYTE** ppDstData, UINT32* pDstSize,
	                                UINT32* pFlags);
	int mppc_decompress(MPPC_CONTEXT* mppc, const BYTE* pSrcData, UINT32 SrcSize,
	                                  const BYTE** ppDstData, UINT32* pDstSize, UINT32 flags);

	void mppc_set_compression_level(MPPC_CONTEXT* mppc, DWORD CompressionLevel);

	void mppc_context_reset(MPPC_CONTEXT* mppc, BOOL flush);

	MPPC_CONTEXT* mppc_context_new(DWORD CompressionLevel, BOOL Compressor);
	void mppc_context_free(MPPC_CONTEXT* mppc);

#ifdef __cplusplus
}
#endif

#endif /* FREERDP_MPPC_H */

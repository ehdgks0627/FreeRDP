# FreeRDP: A Remote Desktop Protocol Implementation
# libfreerdp-core cmake build script
#
# Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(MODULE_NAME "freerdp-codec")
set(MODULE_PREFIX "FREERDP_CODEC")

set(${MODULE_PREFIX}_SRCS
	bulk.h
	nsc_encode.h
	rfx.c
	nsc.c
	jpeg.c
	dsp.c
	rfx_neon.h
	zgfx.c
	rfx_encode.c
	h264.h
	rfx_dwt.h
	rfx_decode.c
	bitmap.c
	rfx_quantization.c
	ncrush.c
	mppc.h
	progressive.h
	region.c
	rfx_rlgr.c
	xcrush.c
	nsc_encode.c
	bulk.c
	rfx_differential.h
	clear.c
	rfx_decode.h
	yuv.c
	h264.c
	rfx_dwt.c
	rfx_encode.h
	rfx_neon.c
	dsp.h
	progressive.c
	mppc.c
	ncrush.h
	rfx_quantization.h
	interleaved.c
	rfx_constants.h
	rfx_types.h
	planar.c
	xcrush.h
	dsp_ffmpeg.h
	audio.c
	color.c
	nsc_types.h
	rfx_bitstream.h
	rfx_rlgr.h
)

freerdp_module_add(${${MODULE_PREFIX}_SRCS})


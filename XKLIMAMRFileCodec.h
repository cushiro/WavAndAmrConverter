//
//  XKLIMAMRFileCodec.h
//  XKLIMKit
//
//  Created by cushiro on 19-4-14.
//  Copyright (c) 2019年 cushiro. All rights reserved.
//

#ifndef XKLIMAMRFileCodec_h
#define XKLIMAMRFileCodec_h
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interf_dec.h"
#include "interf_enc.h"

#define XKLIM_AMR_MAGIC_NUMBER "#!AMR\n"

#define XKLIM_PCM_FRAME_SIZE 160 // 8khz 8000*0.02=160
#define XKLIM_MAX_AMR_FRAME_SIZE 32
#define XKLIM_AMR_FRAME_COUNT_PER_SECOND 50

typedef struct
{
	char chChunkID[4];
	int nChunkSize;
}XKLIMXCHUNKHEADER;

typedef struct
{
	short nFormatTag;
	short nChannels;
	int nSamplesPerSec;
	int nAvgBytesPerSec;
	short nBlockAlign;
	short nBitsPerSample;
}XKLIMWAVEFORMAT;

typedef struct
{
	short nFormatTag;
	short nChannels;
	int nSamplesPerSec;
	int nAvgBytesPerSec;
	short nBlockAlign;
	short nBitsPerSample;
	short nExSize;
}XKLIMWAVEFORMATX;

typedef struct
{
	char chRiffID[4];
	int nRiffSize;
	char chRiffFormat[4];
}XKLIMRIFFHEADER;

typedef struct
{
	char chFmtID[4];
	int nFmtSize;
	XKLIMWAVEFORMAT wf;
}XKLIMFMTBLOCK;

// WAVE音频采样频率是8khz 
// 音频样本单元数 = 8000*0.02 = 160 (由采样频率决定)
// 声道数 1 : 160
//       2 : 160*2 = 320
// bps决定样本(sample)大小
// bps = 8 --> 8位 unsigned char
//       16 --> 16位 unsigned short
int XKLIM_EncodeWAVEFileToAMRFile(const char* pchWAVEFilename, const char* pchAMRFileName, int nChannels, int nBitsPerSample);

// 将AMR文件解码成WAVE文件
int XKLIM_DecodeAMRFileToWAVEFile(const char* pchAMRFileName, const char* pchWAVEFilename);


// 将AMR格式的音频数据转化为WAV格式的音频数据
NSData* XKLIM_DecodeAMRToWAVE(NSData* data);

// 将WAV格式的音频数据转化为AMR格式的音频数据（8KHz采样）
NSData* XKLIM_EncodeWAVEToAMR(NSData* data, int nChannels, int nBitsPerSample);

#endif

//
//  XKLIMVoiceConverter.m
//  XKLIMKit
//
//  Created by cushiro on 19-4-14.
//  Copyright (c) 2019年 cushiro. All rights reserved.
//

#import "XKLIMVoiceConverter.h"

#import "XKLIMAMRFileCodec.h"

@implementation XKLIMVoiceConverter

//转换amr到wav
+ (int)xklim_convertAmrToWav:(NSString *)aAmrPath wavSavePath:(NSString *)aSavePath
{
    if (!XKLIM_DecodeAMRFileToWAVEFile([aAmrPath cStringUsingEncoding:NSASCIIStringEncoding], [aSavePath cStringUsingEncoding:NSASCIIStringEncoding]))
        return 0;
    
    return 1;
}

//转换wav到amr
+ (int)xklim_convertWavToAmr:(NSString *)aWavPath amrSavePath:(NSString *)aSavePath
{
    if (!XKLIM_EncodeWAVEFileToAMRFile([aWavPath cStringUsingEncoding:NSASCIIStringEncoding], [aSavePath cStringUsingEncoding:NSASCIIStringEncoding], 1, 16))
        return 0;
    
    return 1;
}

// 将AMR格式的音频数据转化为WAV格式的音频数据
+ (NSData *)xklim_decodeAMRToWAVE:(NSData *)data
{
    return XKLIM_DecodeAMRToWAVE(data);
}

// 将AMR格式的音频数据转化为WAV格式的音频数据
+ (NSData *)xklim_encodeWAVEToAMR:(NSData *)data
{
    return XKLIM_EncodeWAVEToAMR(data, 1, 16);
}

//获取录音设置
+ (NSDictionary*)xklim_getAudioRecorderSettingDict
{
    NSDictionary *recordSetting = [[NSDictionary alloc] initWithObjectsAndKeys:
                                   [NSNumber numberWithFloat: 8000.0],AVSampleRateKey, //采样率
                                   [NSNumber numberWithInt: kAudioFormatLinearPCM], AVFormatIDKey,
                                   [NSNumber numberWithInt:16],AVLinearPCMBitDepthKey,//采样位数 默认 16
                                   [NSNumber numberWithInt: 1], AVNumberOfChannelsKey,//通道的数目
                                   [NSNumber numberWithBool:NO],AVLinearPCMIsBigEndianKey,//大端还是小端 是内存的组织方式
                                   [NSNumber numberWithBool:NO],AVLinearPCMIsFloatKey,//采样信号是整数还是浮点数
                                   [NSNumber numberWithBool:NO],AVLinearPCMIsNonInterleaved,//是否允许音频交叉
                                   [NSNumber numberWithInt: AVAudioQualityMax],AVEncoderAudioQualityKey,//音频编码质量
                                   nil];
    return recordSetting;
}
    
@end

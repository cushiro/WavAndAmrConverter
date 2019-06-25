//
//  XKLIMVoiceConverter.h
//  XKLIMKit
//
//  Created by cushiro on 19-4-14.
//  Copyright (c) 2019年 cushiro. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface XKLIMVoiceConverter : NSObject

/**
 *  转换wav到amr
 *
 *  @param aWavPath  wav文件路径
 *  @param aSavePath amr保存路径
 *
 *  @return 0失败 1成功
 */
+ (int)xklim_convertWavToAmr:(NSString *)aWavPath amrSavePath:(NSString *)aSavePath;

/**
 *  转换amr到wav
 *
 *  @param aAmrPath  amr文件路径
 *  @param aSavePath wav保存路径
 *
 *  @return 0失败 1成功
 */
+ (int)xklim_convertAmrToWav:(NSString *)aAmrPath wavSavePath:(NSString *)aSavePath;


/*!
 将AMR格式的音频数据转化为WAV格式的音频数据
 
 @param data    AMR格式的音频数据，必须是AMR-NB的格式
 @return        WAV格式的音频数据
 */
+ (NSData *)xklim_decodeAMRToWAVE:(NSData *)data;

/*!
  将WAV格式的音频数据转化为AMR格式的音频数据
 
 @param data    WAV格式的音频数据（8KHz采样率,采样位数16,通道数1）
 @return        AMR格式的音频数据
 */
+ (NSData *)xklim_encodeWAVEToAMR:(NSData *)data;

/**
	获取录音设置.
    建议使用此设置，如有修改，则转换amr时也要对应修改参数，比较麻烦
	@returns 录音设置
 */
+ (NSDictionary*)xklim_getAudioRecorderSettingDict;

@end

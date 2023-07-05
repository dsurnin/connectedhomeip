/**
 *
 *    Copyright (c) 2023 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <Matter/MTRDefines.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MTRCommissionableBrowserDelegate;
@class MTRDeviceController;

MTR_HIDDEN
@interface MTRCommissionableBrowser : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithDelegate:(id<MTRCommissionableBrowserDelegate>)delegate
                      controller:(MTRDeviceController *)controller
                           queue:(dispatch_queue_t)queue;
/**
 * Start browsing the available networks (e.g IP, BLE) for commissionable nodes.
 *
 * If a browse is already ongoing this will not start a new browse and the return value will be NO.
 */
- (BOOL)start;

/**
 * Stop browsing the network for commissionable nodes.
 */
- (BOOL)stop;
@end

NS_ASSUME_NONNULL_END

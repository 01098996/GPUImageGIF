#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "GPUImageContext.h"
#import "GPUImageOutput.h"

/** Protocol for getting Movie played callback.
 */
@protocol GPUImageGIFDelegate <NSObject>

- (void)didCompletePlayingGIF;
@end

/** Source object for filtering movies
 */
@interface GPUImageGIF : GPUImageOutput

@property(readwrite, retain) NSURL *url;

/** This determines whether to play back a movie as fast as the frames can be processed, or if the original speed of the movie should be respected. Defaults to NO.
 */
@property(readwrite, nonatomic) BOOL playAtActualSpeed;

/** This determines whether the video should repeat (loop) at the end and restart from the beginning. Defaults to NO.
 */
@property(readwrite, nonatomic) BOOL shouldRepeat;

/** This specifies the progress of the process on a scale from 0 to 1.0. A value of 0 means the process has not yet begun, A value of 1.0 means the conversaion is complete.
 This property is not key-value observable.
 */
@property(readonly, nonatomic) float progress;

/** This is used to send the delete Movie did complete playing alert
 */
@property (readwrite, nonatomic, assign) id <GPUImageGIFDelegate>delegate;

@property (readonly, nonatomic) BOOL videoEncodingIsFinished;

/// @name Initialization and teardown
- (id)initWithURL:(NSURL *)url;

- (void)startProcessing;
- (void)endProcessing;
- (void)cancelProcessing;

@end


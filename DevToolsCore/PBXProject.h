#import "PBXTarget.h"
#import "XCConfigurationList.h"
#import "XCArchiveFormat.h"


@protocol PBXProject <PBXContainer, NSObject>

+ (id<XCArchiveFormat>)_xcode3_1Format;
+ (id<XCArchiveFormat>)_xcode3_2Format;
+ (id<XCArchiveFormat>)_nativeFormat;
+ (BOOL) isProjectWrapperExtension:(NSString *)extension;
+ (id<PBXProject>) projectWithFile:(NSString *)projectAbsolutePath;


- (NSArray<PBXTarget> *) targets;
- (id<PBXTarget>) targetNamed:(NSString *)targetName;

- (NSString *) name;

- (id<XCConfigurationList>) buildConfigurationList;

- (id<XCArchiveFormat>)preferredProjectFormat;
- (void)setPreferredProjectFormat:(id<XCArchiveFormat>)format;
- (id<XCArchiveFormat>)savedProjectFormat;

// @"Xcode 3.2"
- (NSString *)_compatibilityVersion;
- (void)_setCompatibilityVersion:(NSString *)version;

- (BOOL) writeToFileSystemProjectFile:(BOOL)projectWrite userFile:(BOOL)userWrite checkNeedsRevert:(BOOL)checkNeedsRevert;

@end

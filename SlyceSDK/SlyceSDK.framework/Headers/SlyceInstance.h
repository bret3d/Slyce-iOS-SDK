#import <Foundation/Foundation.h>

#import "SlyceImageMatchingSyncDelegate.h"
#import "SlyceSession.h"
#import "SlyceEventTracker.h"

/*
 Main Slyce workflow entry point
 */
NS_ASSUME_NONNULL_BEGIN
@interface Slyce : NSObject

+ (instancetype)shared;


/*!
 *  @method
 *
 *  @brief Initializes a new Slyce object using valid AccountIdentifier, SpaceIdentifier, and API Key.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality.
 *
 *  @param accountIdentifier the Account Identifier for your organization.
 *  @param apiKey the API Key for your organization.
 *  @param spaceIdentifier the Space Identifier for this SlyceInstance.
 *  @param completion the completion block.
 *
 *  **Important:** Successfully opening the Slyce object is mandatory before you start
 *  performing any tasks in the SDK!
 *
 */
- (void)openWithAccountIdentifier:(NSString *)accountIdentifier apiKey:(NSString *)apiKey spaceIdentifier:(NSString *)spaceIdentifier completion:(void (^)(NSError * _Nullable))completion
NS_SWIFT_NAME(open(accountIdentifier:apiKey:spaceIdentifier:completion:));

/*!
 * @method
 *
 * @brief Closes this instance of Slyce.
 */
- (void)close;

/*!
 * @method
 *
 * @brief The default `SlyceSession`.
 * @return A `SlyceSession` instance.
 */
- (id<SlyceSession>)defaultSession;

/**
 * @property
 * @abstract 2D catalogs sync delegate
 * @discussion This object will receive updates about the 2D catalogs sync progress
 */
@property (nonatomic, weak, nullable) id<SlyceImageMatchingSyncDelegate> imageMatchingSyncDelegate;


#pragma mark Analytics

/**
 * @property
 * @abstract Enables or disables analytics
 * @default YES
 */
@property (nonatomic) BOOL analyticsEnabled;

/**
 * @property
 * @abstract Include location information with analytics, if available.
 * @default YES
 */
@property (nonatomic) BOOL analyticsShouldIncludeLocationInformation;

/**
 * @property
 * @abstract An instance of `SlyceEventTracker` for posting events that occur outside of the SlyceSDK.
 */
@property (nonatomic, readonly) id<SlyceEventTracker> eventTracker;

@end
NS_ASSUME_NONNULL_END

typedef Slyce SFSlyce __deprecated __deprecated_msg("Use 'Slyce' instead.");

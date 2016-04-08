#import "HUBViewControllerFactory.h"

@protocol HUBImageLoaderFactory;
@protocol HUBContentReloadPolicy;
@protocol HUBComponentLayoutManager;
@class HUBViewModelLoaderFactoryImplementation;
@class HUBFeatureRegistryImplementation;
@class HUBComponentRegistryImplementation;
@class HUBInitialViewModelRegistry;

NS_ASSUME_NONNULL_BEGIN

/// Concrete implementation of the `HUBViewControllerFactory` API
@interface HUBViewControllerFactoryImplementation : NSObject <HUBViewControllerFactory>

/**
 *  Initialize an instance of this class with its required dependencies
 *
 *  @param viewModelLoaderFactory The factory to use to create view model loaders
 *  @param imageLoaderFactory The factory to use to create image loaders
 *  @param featureRegistry The feature registry to use to retrieve information about registered features
 *  @param componentRegistry The component registry to use in the view controllers that this factory creates
 *  @param initialViewModelRegistry The registry to use to retrieve pre-computed view models for initial content
 *  @param defaultContentReloadPolicy The default content reload policy used by features not defining their own
 *  @param componentLayoutManager The object that manages layout for components for created view controllers
 */
- (instancetype)initWithViewModelLoaderFactory:(HUBViewModelLoaderFactoryImplementation *)viewModelLoaderFactory
                            imageLoaderFactory:(id<HUBImageLoaderFactory>)imageLoaderFactory
                               featureRegistry:(HUBFeatureRegistryImplementation *)featureRegistry
                             componentRegistry:(HUBComponentRegistryImplementation *)componentRegistry
                      initialViewModelRegistry:(HUBInitialViewModelRegistry *)initialViewModelRegistry
                    defaultContentReloadPolicy:(id<HUBContentReloadPolicy>)defaultContentReloadPolicy
                        componentLayoutManager:(id<HUBComponentLayoutManager>)componentLayoutManager NS_DESIGNATED_INITIALIZER;

#pragma mark - Unavailable initializers

/// This class needs to be initialized with its designated initializer
- (instancetype)init NS_UNAVAILABLE;

/// This class needs to be initialized with its designated initializer
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

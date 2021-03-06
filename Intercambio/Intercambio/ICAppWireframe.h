//
//  ICAppWireframe.h
//  Intercambio
//
//  Created by Tobias Kraentzer on 13.06.16.
//  Copyright © 2016 Tobias Kräntzer. All rights reserved.
//

#import "ICAccountSettingsUserInterface.h"
#import "ICAccountsUserInterface.h"
#import "ICConversationUserInterface.h"
#import "ICRecentConversationsUserInterface.h"
#import <UIKit/UIKit.h>

@class ICAppWireframe;

@protocol ICAppWireframeDelegate <NSObject>
@optional
- (UIViewController<ICRecentConversationsUserInterface> *)viewControllerForRecentConversationsInAppWireframe:(ICAppWireframe *)appWireframe;
- (UIViewController<ICAccountsUserInterface> *)viewControllerForAccountsInAppWireframe:(ICAppWireframe *)appWireframe;
- (UIViewController<ICConversationUserInterface> *)viewControllerForConversationInAppWireframe:(ICAppWireframe *)appWireframe;
- (UIViewController<ICAccountSettingsUserInterface> *)viewControllerForAccountSettingsInAppWireframe:(ICAppWireframe *)appWireframe;

- (UINavigationController *)appWireframe:(ICAppWireframe *)appWireframe navigationControllerForPrimaryViewController:(UIViewController *)primaryViewController;

- (UIAlertController *)alertForNewAccountInAppWireframe:(ICAppWireframe *)appWireframe;
- (UIAlertController *)alertForSelectingAccountInAppWireframe:(ICAppWireframe *)appWireframe withCompletion:(void (^)(NSURL *accountURI))completion;
@end

@interface ICAppWireframe : NSObject

@property (nonatomic, weak) id<ICAppWireframeDelegate> delegate;
@property (nonatomic, strong) UIWindow *window;

#pragma mark Main User Interface
- (void)presentLaunchScreen;
- (void)presentMainInterface;
- (void)presentUnrecoverableError:(NSError *)error;

#pragma mark Conversations
- (void)presentUserInterfaceForConversationWithURI:(NSURL *)conversationURI
                                fromViewController:(UIViewController *)viewController;
- (void)presentUserInterfaceForNewConversationFromViewController:(UIViewController *)viewController;

#pragma mark Accounts
- (void)presentUserInterfaceForAccountWithURI:(NSURL *)accountURI
                           fromViewController:(UIViewController *)viewController;
- (void)presentUserInterfaceForNewAccountFromViewController:(UIViewController *)viewController;
- (void)presentUserInterfaceForSelectingAccountFromViewController:(UIViewController *)viewController
                                                       completion:(void (^)(NSURL *accountURI))completion;

#pragma mark Sharing
- (void)presentShareUserInterfaceForAccountWithURI:(NSURL *)accountURI
                                fromViewController:(UIViewController *)viewController
                                            sender:(id)sender;

@end

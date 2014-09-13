//
//  CenterViewController+Bottom.m
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "CenterViewController+Bottom.h"
#import "UrgentViewController.h"
#import "CrossingConfigViewController.h"

@implementation CenterViewController (Bottom)

#pragma mark - Private Methods
- (void) hideBottomView:(BOOL)hidden
{
    CGRect bottomViewFrame = self.bottomView.frame;
    CGRect frame;
    if (hidden)
    {
        if (fabs(frame.size.height - bottomViewFrame.origin.y - bottomViewFrame.size.height) < 1)
        {
            CGRect destFrame = bottomViewFrame;
            destFrame.origin.y = frame.size.height - 15;  //15是MainBottomView的topView的高度
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
    }
    else
    {
        if (fabs(frame.size.height - bottomViewFrame.origin.y - 15) < 1)
        {
            CGRect destFrame = bottomViewFrame;
            destFrame.origin.y = frame.size.height - bottomViewFrame.size.height;  //15是MainBottomView的topView的高度
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
    }
}

#pragma mark - ButtonView Methods
- (IBAction)runmonitor:(UITapGestureRecognizer *)gesture
{
    
}

- (IBAction)videoMonitor:(id)sender
{
    
}

- (IBAction)interactionSet:(id)sender
{
    CrossingConfigViewController *config = [[CrossingConfigViewController alloc] initWithStyle:UITableViewStylePlain];
    [config setCrossing:_currentCrossing];
    [self.navigationController pushViewController:config animated:YES];
}

- (IBAction)urgent:(id)sender
{
    UrgentViewController *urgent = [[UrgentViewController alloc] init];
    [self.navigationController pushViewController:urgent animated:YES];
}

- (IBAction)topViewTapped:(id)sender
{
    CGRect bottomViewFrame = self.bottomView.frame;
    CGRect bounds = self.view.bounds;
    if (fabs(bounds.size.height - bottomViewFrame.origin.y - bottomViewFrame.size.height) < 1)
    {
        // 隐藏
        CGRect destFrame = bottomViewFrame;
        destFrame.origin.y = bounds.size.height - 15;  //15是MainBottomView的topView的高度
        [UIView animateWithDuration:0.2 animations:^{
            self.bottomView.frame = destFrame;
        } completion:^(BOOL finished) {
        }];
    }
    else if (fabs(bounds.size.height - bottomViewFrame.origin.y - 15) < 1)
    {
        // 显示
        CGRect destFrame = bottomViewFrame;
        destFrame.origin.y = bounds.size.height - bottomViewFrame.size.height;  //15是MainBottomView的topView的高度
        [UIView animateWithDuration:0.2 animations:^{
            self.bottomView.frame = destFrame;
        } completion:^(BOOL finished) {
        }];
    }
}

- (IBAction)topViewPan:(UIPanGestureRecognizer *)pan
{
    return;
    if (pan.state == UIGestureRecognizerStateChanged)
    {
        CGRect bounds = self.view.bounds;
        CGPoint offset = [pan translationInView:self.view];
        
        CGRect bottomViewFrame = self.bottomView.frame;
        CGRect destFrame = bottomViewFrame;
        if ((fabs(bounds.size.height - bottomViewFrame.origin.y - bottomViewFrame.size.height) < 1)
            || (fabs(bounds.size.height - bottomViewFrame.origin.y - 15) < 1))
        {
            return;
        }
        else if (fabs(bounds.size.height - bottomViewFrame.origin.y - bottomViewFrame.size.height) < 5)
        {
            destFrame.origin.y = bounds.size.height - 15;  //15是MainBottomView的topView的高度
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
        else if (fabs(bounds.size.height - bottomViewFrame.origin.y - 15) < 5)
        {
            destFrame.origin.y = bounds.size.height - bottomViewFrame.size.height;  //15是MainBottomView的topView的高度
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
        else
        {
            destFrame.origin.y += offset.y;  //15是MainBottomView的topView的高度
            [pan setTranslation:CGPointZero inView:self.view];
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
    }
    else if (pan.state == UIGestureRecognizerStateEnded)
    {
        CGRect bottomViewFrame = self.bottomView.frame;
        CGRect bounds = self.view.bounds;
        if (fabs(bounds.size.height - bottomViewFrame.origin.y) <= bottomViewFrame.size.height/2)
        {
            // 隐藏
            CGRect destFrame = bottomViewFrame;
            destFrame.origin.y = bounds.size.height - 15;  //15是MainBottomView的topView的高度
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
        else
        {
            // 显示
            CGRect destFrame = bottomViewFrame;
            destFrame.origin.y = bounds.size.height - bottomViewFrame.size.height;  //15是MainBottomView的topView的高度
            [UIView animateWithDuration:0.2 animations:^{
                self.bottomView.frame = destFrame;
            } completion:^(BOOL finished) {
            }];
        }
    }
}

@end

//
//  CenterViewController+Bottom.h
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "CenterViewController.h"

@interface CenterViewController (Bottom)

// 运行监控
- (IBAction)runmonitor:(UITapGestureRecognizer *)gesture;
// 视屏监控
- (IBAction)videoMonitor:(id)sender;
// 路口设置
- (IBAction)interactionSet:(id)sender;
// 紧急控制
- (IBAction)urgent:(id)sender;


- (IBAction)topViewTapped:(id)sender;
- (IBAction)topViewPan:(UIPanGestureRecognizer *)pan;

@end

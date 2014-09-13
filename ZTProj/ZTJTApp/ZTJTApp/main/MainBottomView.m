//
//  MainBottomView.m
//  ZTJTApp
//
//  Created by Perry on 14-9-6.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "MainBottomView.h"

@implementation MainBottomView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

//// 刷新
//- (void) update:(Intersections *)interaction
//{
//    
//}


- (UIView *) hitTest:(CGPoint)point withEvent:(UIEvent *)event
{
    if (point.y >= -15 && point.y <= 15)
    {
        return self.topView;
    }
    else
    {
        return [super hitTest:point withEvent:event];
    }
}

@end

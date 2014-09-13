//
//  CrossingConfigViewController.h
//  ZTJTApp
//
//  Created by Perry on 14-9-7.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CrossingConfigViewController : UITableViewController
{
    Crossing *_crossing;
}

- (void) setCrossing:(Crossing *)crossing;
@end

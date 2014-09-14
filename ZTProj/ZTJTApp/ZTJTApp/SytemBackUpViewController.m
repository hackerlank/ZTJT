//
//  SytemBackUpViewController.m
//  ZTJTApp
//
//  Created by Perry on 14-9-14.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "SytemBackUpViewController.h"

@interface SytemBackUpViewController ()

@end

@implementation SytemBackUpViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:@"备份" style:UIBarButtonItemStyleBordered target:self action:@selector(backup:)];
    self.navigationItem.rightBarButtonItem = item;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)backup:(id)sender {
}
@end

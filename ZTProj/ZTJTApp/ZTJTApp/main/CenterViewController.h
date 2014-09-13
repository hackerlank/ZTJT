
#import <UIKit/UIKit.h>
#import "MainBottomView.h"

@interface CenterViewController : UIViewController <MKMapViewDelegate>
{
    Crossing *_currentCrossing;
}


@property (weak, nonatomic) IBOutlet MainBottomView *bottomView;

@property (weak, nonatomic) IBOutlet UILabel *mainBottomViewTitleLable;

@end

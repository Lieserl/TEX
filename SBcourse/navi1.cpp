//点击了“立即购买” 
onClickBuyNow(event){
    createOrderFromStore(this.data.goodDetail.goodId);
    wx.navigateTo({
        url:'/pages/order/confirm/index',
    })
}
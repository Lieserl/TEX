//去结算 
onClickToConfirm(e){
    if(this.data.cartData.totalPrice <= 0) {
        return;
    }
    createOrderFromCart();
    wx.navigateTo({
        url: '/pages/order/confirm/index',
    })
}
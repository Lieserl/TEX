bool check_circle(LinkList L)
{
    if (!L) return false;

    LNode *slow = L, *fast = L;

    while (fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }

    return false;
}
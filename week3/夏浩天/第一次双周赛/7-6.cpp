#include<iostream>
#include<algorithm>
using namespace std;
int lp[9];
int main()
{
	string a;
	cin >> a;
	int n = a.size();
	//假设这里是排序
	int b[8];
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		a[i] = b[i];
	lp[n] = 1;
	for (int i1 = 0; i1 < n; i1++)
	{
		if (!lp[1])
			for (int i2 = 0; i2 < n; i2++)
			{
				if (!lp[2])
				{
					if (i2 != i1)
						for (int i3 = 0; i3 < n; i3++)
						{
							if (!lp[3])
							{
								if (i3 != i2 && i3 != i1)
								{
									for (int i4 = 0; i4 < n; i4++)
									{
										if (!lp[4])
										{
											if (i4 != i3 && i4 != i2 && i4 != i1)
											{
												for (int i5 = 0; i5 < n; i5++)
												{
													if (!lp[5])
													{
														if (i5 != i4 && i5 != i3 && i5 != i2 && i5 != i1)
														{
															for (int i6 = 0; i6 < n; i6++)
															{
																if (!lp[6])
																{
																	if (i6 != i5 && i6 != i4 && i6 != i3 && i6 != i2 && i6 != i1)
																	{
																		for (int i7 = 0; i7 < n; i7++)
																		{
																			if (!lp[7])
																			{
																				if (i7 != i6 && i7 != i5 && i7 != i4 && i7 != i3 && i7 != i2 && i7 != i1)
																					for (int i8 = 0; i8 < n; i8++)
																					{
																						if (i8 != i7 && i8 != i6 && i8 != i5 && i8 != i4 && i8 != i3 && i8 != i2 && i8 != i1)
																							cout << a[i1] << a[i2] << a[i3] << a[i4] << a[i5] << a[i6] << a[i7] << a[i8] << endl;
																					}
																			}
																			else if (i7 != i6 && i7 != i5 && i7 != i4 && i7 != i3 && i7 != i2 && i7 != i1)
																				cout << a[i1] << a[i2] << a[i3] << a[i4] << a[i5] << a[i6] << a[i7] << endl;

																		}
																	}
																}
																else if (i6 != i5 && i6 != i4 && i6 != i3 && i6 != i2 && i6 != i1)
																	cout << a[i1] << a[i2] << a[i3] << a[i4] << a[i5] << a[i6] << endl;
															}
														}
													}
													else if (i5 != i4 && i5 != i3 && i5 != i2 && i5 != i1)
														cout << a[i1] << a[i2] << a[i3] << a[i4] << a[i5] << endl;
												}
											}
										}
										else if (i4 != i3 && i4 != i2 && i4 != i1)
											cout << a[i1] << a[i2] << a[i3] << a[i4] << endl;
									}
								}
							}
							else if (i3 != i2 && i3 != i1)
								cout << a[i1] << a[i2] << a[i3] << endl;
						}
				}
				else if(i2 != i1)
					cout << a[i1] << a[i2] << endl;
			}
		else
			cout << a[i1] << endl;
	}
}
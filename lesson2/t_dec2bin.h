int t_dec2bin_rec_2 (int dec, int i) {
	if (dec == 0) return 0;
	if (dec % 2 != 0) return t_pow(10, i) + t_dec2bin_rec_2(dec / 2, ++i);
	return t_dec2bin_rec_2(dec / 2, ++i);
}

int t_dec2bin_rec (int dec) {
	return t_dec2bin_rec_2(dec, 0);
}